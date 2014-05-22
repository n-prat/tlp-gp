/*!
 * \file main.cpp
 * \brief This program parse PDDL 3.1 TE domain and problem corresponding file, then it solve the planning problem following TLP-GP1 and TLP-GP2 algorithms
 * \author Alan BENIER, Martin LAGLEIZE, Nathan PRAT
 * \version 1.0
 * \date May 07th 2014
 */

#include "parser/Parser.h"

using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <time.h>

#include "src/graph1.h"
#include "src/graph2.h"
#include "src/tlpgp1.h"
#include "src/tlpgp2.h"

int g_pid = int(getpid());

/*!
 * \brief This program parse PDDL 3.1 TE domain and problem corresponding file, then it solve the planning problem following TLP-GP1 and TLP-GP2 algorithms
 * \param domainFile.pddl problemFile.pddl
 * \return Print the result of the planner on stdout
 */
int main(int argc, char **argv)
{
	clock_t t1, t2;
	t1 = clock();
	Parser parser_domain;
	FILE *domain_file = nullptr, *problem_file = nullptr;
	Data *data = nullptr;

	Graph2 *graph2 = nullptr;
	Domain * domain = nullptr;
	Problem * problem = nullptr;

	// argument verification
	if (argc != 4) {
		cerr << "Usage :\n\t" << argv[0] << " need three paramaters ( example : ./prog domain.pddl problem.pddl 2" << endl;
		exit(1);
	}

	if (string(argv[3]) != "2" && string(argv[3]) != "1"){
		cerr << "Usage :\n\t" << argv[0] << " domainFile.pddl problemFile.pddl 1|2" << endl;
		exit(1);
	}	

	// file verification
	if ((domain_file = fopen(argv[1], "r")) == NULL) {
		cerr << argv[1] << " cannot be opened." << endl;
		exit(2);
	}

	if ((problem_file = fopen(argv[2], "r")) == NULL) {
		cerr << argv[2] << " cannot be opened." << endl;
		exit(3);
	}

	// the parser parse stdin, so the file must be redirected, it's done manually here
	dup2(fileno(domain_file), STDIN_FILENO);

	// this file won't be needed anymore
	if (fclose(domain_file) != 0) {
		cerr << argv[1] << " cannot be closed." << endl;
		exit(4);
	}

	// starting of the parsing
	parser_domain.init();
	if (parser_domain.parse() == 0) { // if the parsing of the domain is successful
		cout << "The domain was successfully parsed" << endl;

		// then we can continue and parse the problem
		Parser parser_problem;

		// we link the data from the domain parser to the new problem parser
		// this must be done, unless the parser cannot be restarted
		parser_problem.setData(&parser_domain);
		dup2(fileno(problem_file), STDIN_FILENO);

		// again, this file won't be needed anymore
		if (fclose(problem_file) != 0) {
			cerr << argv[2] << " cannot be closed." << endl;
			exit(5);
		}

		if (parser_problem.parse() == 0) { // if the parsing of the domain is successful
			cout << "The problem was successfully parsed" << endl;

			// we keep the data that have been generated by the parser, to use it in the planner
			data = parser_problem.getData();
		}
		else { // if something went wrong in the parsing of the problem, then aborting
			cout << "The problem failed to be parsed" << endl;
			exit(6);
		}
	}
	else { // if something went wrong in the parsing of the domain, then aborting
		cout << "The domain failed to be parsed" << endl;

		// closing of the problem file which will be unused
		if (fclose(problem_file) != 0) {
			cerr << argv[2] << " cannot be closed." << endl;
			exit(5);
		}

		exit(7);
	}
	// display the data that result of the parsing, and the errors that happened
	//data->display();

	// we link the relevant data for the planner
	domain = data->getDomain();
	problem = data->getProblem();

	cout<<"Domain : "<<domain->getName()<<"\t| Problem : "<<problem->getName()<<endl;

	// we launch the planner
	// TLP-GP 2
	if(string(argv[3]) == "2"){
		graph2 = new Graph2(domain, problem);
		if (!graph2->generateGraph()){
			cout<<"No solution \n";
		}
	}
	else if(string(argv[3]) == "1"){
		Tlpgp1 *tlpgp1 = new Tlpgp1(domain, problem);
		tlpgp1->constructGraph();
	}
	else
		cerr <<" last argument must be 1 or 2" << endl;

	t2 = clock();	
	cout<<"Total time : "<<(float)(t2-t1)/CLOCKS_PER_SEC<<"\n";
	//vertex->to_string();

	//tlpgp1 = new Tlpgp1(domain, problem);
	//tlpgp1->generateGraph();

	return 0;
}


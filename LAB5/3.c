#include<stdio.h>
#include<conio.h>

void createSolutionStruct();
void sortSubSets();
void greedy();
int numberOfUncoveredElements(int subSetIndex);


void greedy() {
	int i;
	int temp;
	bestSolution->nSolutionSize = 0;
	addSubSet(bestSolution, 0);
	int addIndex = 0;
	int addNumber = 0;

	while(!checkSolution(bestSolution)) {
		addIndex = 0;
		addNumber = 0;
		for(i=0; i<set->nSubSets; i++) {
			if(!containsSubSet(bestSolution, i)) {
				temp = numberOfUncoveredElements(i);
				if(temp > addNumber) {
					addNumber = temp;
					addIndex = i;
				}
			}
		}
		addSubSet(bestSolution, addIndex);
	}
	printSolution(bestSolution);
}

int numberOfUncoveredElements(int subSetIndex) {
	int i;
	int count=0;

	for(i=0; i<set->nSubSetSizes[subSetIndex]; i++) {
		if(!bestSolution->boolIncluded[set->subsets[subSetIndex][i] - 1])
			count++;
	}

	return count;
}

void sortSubSets() {
	int i,j;
void createSolutionStruct() {
                  bestSolution->subSets[i] = -1;
	bestSolution->boolIncluded = malloc(sizeof(int) * set->nGlobalSetSize);
	memset(bestSolution->boolIncluded, 0, set->nGlobalSetSize);
	bestSolution->nSolutionSize = (int)set->nSubSets-1;
	bestSolution->nSolutionSize = set->nSubSets-1;
}



//	backtracking (Tuple &sol, int k) { -----> k=current level of the exploration tree
//		prepareLevelTraverse(k);  -----> generates candidates to complete the sol in the ext step
//		while(!lastSiblingInLevel(k)){  -----> last candidate partial solution
//			sol[k] = nextSiblingInLevel(k); -----> provides all the candidate partial solutions
//			if (isValid(sol, k)){  -----> checks the current solution to see if it meets the restrictions
//				if (isSolution(sol, k)) -----> is an end of the search
//					treatSolution(sol); ----> its a final solution
//				else
//					backtracking(sol, k + 1); -----> moves to the next level
//			}
//		}
//	}


//						WITH MARKS

//	backtrackingWithMarks (Tuple &sol, int k, Mark &marks){
//		prepareLevel(k);
//		while(!lastCandidateInLevel(k)){
//			sol[k] = nextCandidateInLevel(k);
//			if (isValid(sol, k, marks)){
//				if (isSolution(sol, k))
//					treatSolution(sol);
//				else{
//					mark(marks, sol, k);
//					backtrackingWithMarks(sol, k + 1, marks);
//					unmark(marks, sol, k);
//				}
//			}
//		}
//	}

#pragma once
#include<cstdio>
#include<cstring>
#include "STJAlgorithm.h"
class GAME{
	public :
		GAME():NUMBS(8), MARKS(4){}
		
		void init(){
			clear();
			for (int i = 0 ; i < 8 ; ++i)
				scanf("%d", numb + i) ;
		}
		
		void calc(){
			do{
				do{
					if (judge()){
						print() ;
						return ;
					}
				}while(++MARKS) ;
				MARKS.set(4) ;
				++NUMBS ;
			}while(++NUMBS) ;
			puts("cannot find a solution!") ;
		}
		
	private :
		STJAlgorithm NUMBS ;
		STJAlgorithm MARKS ;
		int numb[8] ;
		int opr[4][3] = {{0, 1, 2}, {0, 3, 6}, {1, 4, 7}, {3, 4, 5}} ;
		bool (GAME::*fuc[4]) (int a, int b, int c) = {jud_plus, jud_minus, jud_div, jud_mul};
		char alph[4] = {'+', '-', '/', '*'} ;
		
		bool jud_plus(int a, int b, int c){
			return a + b == c ;
		}
		
		bool jud_minus(int a, int b, int c){
			return a - b == c ;
		}
		
		bool jud_div(int a, int b, int c){
			return b * c == a ; 
		}
		
		bool jud_mul(int a, int b, int c){
			return a * b == c ;
		}
		
		void clear(){
			NUMBS.set(8) ;
			MARKS.set(4) ;
			memset(numb, sizeof(numb), 0) ;
		}
		
		bool judge(){
			static int seq[8];
			for (int i = 0 ; i < 8 ; ++i)
				seq[i] = numb[NUMBS[i]] ;
			bool flg = 1 ;
			for (int i = 0 ; i < 4 ; ++i){
				flg &= (this->*fuc[MARKS[i]])(seq[opr[i][0]], seq[opr[i][1]], seq[opr[i][2]]) ;
			}
			return flg ;
		}
		
		void print(){
			int seq[8];
			for (int i = 0 ; i < 8 ; ++i)
				seq[i] = numb[NUMBS[i]] ;
			printf("%d %c %d = %d\n %c  %c\n%d %c %d = %d\n =  =\n%d  %d",
				seq[0], alph[MARKS[0]], seq[1], seq[2],
				alph[MARKS[1]], alph[MARKS[2]],
				seq[3], alph[MARKS[3]], seq[4], seq[5],
				seq[6], seq[7]) ;
		} 
};


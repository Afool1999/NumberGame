#pragma once
#include<cstdio>
class STJAlgorithm{
	public :
		STJAlgorithm(){}
		
		STJAlgorithm(int _seq_len){
			init(_seq_len);
		}
		
		~STJAlgorithm(){
			delete [] seq_front;
			delete [] dir_front;
		}
		
		void init(int _seq_len){
			seq_front = new int[_seq_len];
			dir_front = new int[_seq_len];
			int *h1, *h2;
			h1 = seq_front;
			h2 = dir_front;
			for (int i = 0; i < _seq_len; ++i){
				*h1 = i;
				*h2 = -1;
				++h1;
				++h2;
			}
			seq_rear = seq_front + _seq_len;
		}
		
		bool findnxt(){
			int *seq_pos, *dir_pos;
			seq_pos = NULL;
			dir_pos = NULL;
			int *h_seq = seq_front;
			int *h_dir = dir_front; 
			for (; h_seq<seq_rear; ++h_seq, ++h_dir){
				int *suc_pos = h_seq + *h_dir;
				if (is_inside(suc_pos) && *h_seq>*suc_pos){
					if (seq_pos==NULL || *h_seq>*seq_pos){
						seq_pos = h_seq;
						dir_pos = h_dir;
					}
				}
			}
			if (seq_pos == NULL){
				return 0;
			}
			h_seq = seq_front;
			h_dir = dir_front;
			for (; h_seq<seq_rear; ++h_seq, ++h_dir){
				if (*h_seq > *seq_pos){
					*h_dir = -*h_dir;
				}
			}
			swap(*seq_pos, *(seq_pos + *dir_pos));
			swap(*dir_pos, *(dir_pos + *dir_pos));
			return 1;
		}
		
		int operator[](int x){
			if (!is_inside(seq_front + x)){
				return NULL;
			}
			return seq_front[x];
		}
		
		bool operator ++(){
			return findnxt();
		}
		
		void set(int _seq_len){
			delete [] seq_front;
			delete [] dir_front;
			init(_seq_len);
		}
		
		void print(){
			int *h_seq = seq_front;
			for (; h_seq<seq_rear; ++h_seq){
				printf("%d ",*h_seq);
			}
			putchar('\n');
		}
		
	private :
		int *seq_front;
		int *dir_front;
		int *seq_rear;
		
		bool is_inside(int *suc_pos){
			return suc_pos>=seq_front && suc_pos<seq_rear;
		}
		
		template <class T>
		void swap(T &a,T &b){
			T c = a;
			a = b;
			b = c;
		}
};

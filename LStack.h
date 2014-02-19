// Filename: LStack.h
// Date Created: 05/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_stack_H
#define LANCE_stack_H
namespace lance_project {
	template <class T>
	class LStack {
		public:
			// The default constructor for the stack.
			LStack();

			// Destructor for the stack.
			~LStack();
			
			void push(T* value);
			
			T* pop();
			
			// The size method returns the size of the stack.
			int size();
			
			// The empty method returns a boolean true if the
			// stack has no elements.
			bool empty();
			
			// The front method returns the front value without
			// removing the element from the stack.
			T* front();
			
			LinkedList<T>* getList();
		private:
			// The linked list stores the data.
			LinkedList<T>* linked_list;
	};
	template <class T>
	ostream & operator<<(ostream & out, LStack<T>* value);
}
#include "LStack.template"
#endif

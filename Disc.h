// Filename: Disc.h
// Date Created: 04/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_DISC_H
#define LANCE_DISC_H
using namespace std;
namespace lance_project {
	class Disc {
		public:			
			Disc(string value);
			
			~Disc();
			
			void setValue(string value);
			
			string getValue();
			
			int getCount();
		private:
			string value;
	};
	ostream & operator<<( ostream & out, Disc * obj );
}
#endif

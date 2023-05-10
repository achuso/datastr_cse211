#include "myQueue.h"

class Bank {
	private:
		MyQueue eliteQ;
		MyQueue normalQ;
	public:
		void add(int age, int type) {
			if(type == 1) // type 1 = elite
				eliteQ.enqueue(age);
			else normalQ.enqueue(age);	
		}
		
		int serveNext() {
			static int eliteCounter = 0; // serve elites. when it hits 3, serve a normal queue person, then set it back to zero
	
			if(!normalQ.isEmpty() && (eliteCounter == 3 || eliteQ.isEmpty())) {
				eliteCounter = 0;
				
				int served_age = normalQ.peek();
				normalQ.dequeue();
				return served_age;
			}
			
			else if(!eliteQ.isEmpty()) {
				eliteCounter++;
				
				int served_age = eliteQ.peek();
				eliteQ.dequeue();
				return served_age;
			}

			else return -1;
					

		}
		
		void serveAll() {
			int ageFlag;
			do {
				if( (ageFlag = serveNext()) != -1 )
					std::cout << ageFlag << " is served." << std::endl;
				else {
					std::cout << "Queues have been emptied. Quitting.." << std::endl;
					break;
				};
			} while(1);
				
		}
};

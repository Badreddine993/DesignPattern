


#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using  namespace std ;



class TaskObserver{
	virtual ~TaskObserver()=default;
	
public:
	void update(std::vector<string>& tasks,string CurrentTemperature) = 0;

	const string getName() const = 0;
}



class ISubject{
	public:
		virtual ~ISubject() = default;
		void attache(std::shared_ptr<TaskObserver> observer)=0;
		void detach(std::shared_ptr(TaskObserver) observer)=0;
		void Notify()=0;


}

class TodoList: public ISubject{
	public:
		vector<shared_ptr<TaskObserver>> observers;
		vector<std::string> tasks;
		float CurrentTemperature;
	public:
		void attach(shared_ptr<TaskObserver> observer) override {
			observers.push_back(observer);
			std::cout<< "we are attaching the observer" << observer.getName()<<std::endl;
		}
	
		void  detach(shared_ptr<TaskObserver> observer) override {
			// bcs we can have multip observer we need to find the observer that we need to change
			auto it = find(observers.begin(),observers.end(), observe);

			if(it!=observers.end()){
				std::cout<<"Detached observer"<< (*it->getName())<<std::endl;
			}
		}

		void Notify() override {

			for(const auto& observer:observers){
				observer->update(tasks,currentTemperature);
			}
			
		}


		void addTask(std::string& task){

			if(!task.empty()){
			tasks.push_back(task);
			std::cout << "your task is added succufully "<< std::endl;//
			}else{
				std::cout<< "your task is empty we cant add "<<std::endl;

			}
			
		}

		void remove(int index){
			if(index >  0 && index < tasks.size()){
				std::string removeTask = tasks[index];
				tasks.erase(tasks.begin()+index);
				cout<< "task has been removed" << removedTask << std::endl;
				notify();
			}else{
				cout << "invalide task index "<<std::endl;
			}
			
		}
		

		void updateTemperature(float temp){
			CurrentTemperature = temp;
			notify();
		}

	



}

class ConsoleDisplay : public TaskObserver{

	void update(const std::vector<std::string> tasks,float temperature) override {
		cout<<" display taskOBserver Console "<<endl;
		cout << "display temperatur" << temperature << "C" << std::endl;
		std::cout << "display tasks in our subject"<<endl;
		if(tasks.empty()){
			;
		}
		
	}
}


int main(){

}

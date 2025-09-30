#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory> 
#include <ostream>
#include <string> 
#include <vector>



							


class TaskObserver{
	public: 

		virtual ~TaskObserver() = default;

		virtual void update(std::vector<std::string> tasks, float temp)=0;

		virtual void getName() const = 0 ;

};




class UISubject {
	public :
		virtual ~UISubject( )= default;

		virtual void attach(std::shared_ptr<TaskObserver>);
		virtual void detach(std::shared_ptr(TaskObserver));
		virtual void Notify();

}




class ToDoList : public UISubject{

	public:
		std::vector<std::string> tasks;
		float CurrentTemperature;
		std::vector<std::shared_ptr<TaskObserver>> observers;

void addTask(const std::vector<std::string>& task){
			if(tasks.empty()){
				std::cout<<"your task list is empty"<<endl;
			}else{
				tasks.push_back(task);
				std::cout<<"your task is added succefullly "<<endl;	
			}
			Notify();

		}

		void Notify() override {
			for(auto observer : observers){
				observer->update(std::vector<std::string>& tasks,float Temperatur);
			}
		}

		void attache(std::shared_ptr<TaskObserver> observer){
			observers.push_back(observer);
		}

		void detache(std::shared_ptr<TaskObserver> observer){
			auto it = observers.find(observers.begin(),observers.end(),observer)
				if(!it = observers.end()){
					std::cout << "your detach the observer" << it << endl;
					observers.erase(it);
				}
		}


		std::vector<std::string> getTasks(){
			return tasks;
		}


		void removeTask(int index ){

			if(tasks.empty()){
				std::cout << "your Todolist is empty no tasks to erase" << endl;

			}else{
				if(index >0 && index< tasks.size()){
				std::string taskremoved = tasks[index]


				tasks.erase(tasks.begin() + index);
				Notify();
				}

			}
		}

};


// lets creat some concrete observver to undertannd lets  Startby creating an UIOBSERVVVER


class ConsolDisplay : public TaskObserver{

	void update (std::vector<std::string > tasks, float Temp) override{
		std::cout << "============================= DisplayTaskConsole==============================="<< endl;
		if(tasks.empty()){

			std::cout<< "your tasks list is empty " << endl;

		}else{
			for(size_t i  = 0 ; i < tasks.size(); size_t ++){
						
				std::cout <<  "  " << "." << i + 1 << tasks[i] << endl;
			}
		}	
	}

	std::string getName() override {
		return " ConsolDisplay"; 
	}


};

class TaskCounter: public TaskObserver {

	void update(std::vector<std::string>& tasks ,float temp) override{
		std::cout << "your task counter" << tasks.size() << endl;



	}
	
	std::string getName() const{
		return "Task Counter";
	}




};

class TemperatureAlert: public TaskObserver {


	void update(std::vector<std::string>& tasks; float temp){
		std::cout << "======================== THE Temperature Alert" << endl;
		if( 50 < temp < 89){
			std::cout<< "the temperature is so hight make your protective "  << endl;
		}
	}

	string getName() override {

		return "Temperature AletL"
	}










};





void getValidateInput(const std::string& prompt , int min , int max ){
	int value;
	while(true){
		std::cout<<prompt;
		if(std::cin >> value && value >= min && value  <= max){
			std::cin.ignore(std::numeric_limits<streamsize> :: max(),'\n');
			return value;
		}else{
			std::cout << "Ivalid input entre a number between " << min << "and"<< max<<std::endl;
			
		}

	}
}
void getValidatedFloatInput(const std::string& prompt , int min , int max){
	return ;
}




int main(){

    ToDoList OurTodoList;

    auto consol = std::make_shared<ConsolDisplay>();
    auto alert = std:: make_shared<TemperatureAlert>();
    auto counter = std::make_shared<counter>();
    
    OurTodoList.attach(consol);
    OurTodoList.attach(alert);
    OurTodoList.attach(counter);




    while (true) {

	    std::cout<<"\n My main Meny" << std::endl;
	    std::cout << "1. Add Task"<<std::endl;
	    std::cout << "2 Remove task"<< std::endl;
	    std::cout << "3 Update temperature" << std::endl;
	    std::cout << "4 Display Current State" << std::endl;
	    std::cout << "5 Manage Observers " << std::endl;
	    std::cout << "6 Exit" << std::endl;
	    int choice = getValidatedFloatInput("Enter a choice (1-6)",1,6);
	    

    
    }

    

    // now i'll creat an UI SUBJECT TO FIND THE SUBJECT 







} 

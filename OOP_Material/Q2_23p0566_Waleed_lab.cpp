#include <iostream>
#include <string>
using namespace std;

class FoodItem //Food Item Class 
{
private:
    //data members
    string name;
    float calories;
    float fatGrams;
    float carbsGrams;
    float protienGrams;

public:
   // Paramterized Constructor with only name Parameter
    FoodItem(string name){
        this->name = name;
        calories=0.0;
        fatGrams=0.0;
        carbsGrams=0.0;
        protienGrams=0.0;
    }

   // Paramterized Constructor with only name Parameter and calorie parameter
    FoodItem(string name, float Calorie){
     this->name = name;
     calories = Calorie;
     fatGrams=0.0;
     carbsGrams=0.0;
     protienGrams=0.0;
     
    }

   // Paramterized Constructor with all Parameters
    FoodItem(string name, float calories, float fatGram, float carbsGrams, float protienGrams){
        this->name=name;
        this->calories=calories;
        this->fatGrams=fatGrams;
        this->carbsGrams=carbsGrams;
        this->protienGrams=protienGrams;
}

    //setters
    void setName(string n){
        name=n;
    }

    void setCalories(float c){
        if(c<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Calories Cannot be Nwgative"<<endl;
        }
        else{
        calories=c;
        }
    }

    void setfatGrams(float fat){
        if(fat<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Calories Cannot be Nwgative"<<endl;
        }
        else{
        fatGrams=fat;
    }
    }

    void setCarbsGram(float carbs){
        if(carbs<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Calories Cannot be Nwgative"<<endl;
        }
        else{
        carbsGrams=carbs;
    }
    }

    void setProtienGrams(float protien){
        if(protien<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Calories Cannot be Nwgative"<<endl;
        }
        else{
        protienGrams=protien;
    }
    }

    //getters
    string getName(){
        return name;
    }

    float getCalories(){
        return calories;
    }

    float getFatGram(){
        return fatGrams;
    }

    float getCarbsGram(){
        return carbsGrams;
    }

    float getProtienGrams(){
        return protienGrams;
    }

   friend int calculateCalories(FoodItem &item);
};

//friend function 'calculateCalories(passing ibject as parameters)'
int calculateCalories(FoodItem &item){
    return (4*item.carbsGrams) + (4 * item.protienGrams) + (9 * item.fatGrams);
}

int main()
{
    string itemName;
    float itemCarbs, itemProtein,itemFatGrams;

    while(1){
        cout<<"Enter name of Food Item (or type 'exit' to quit): ";
        getline(cin,itemName); //getting item name through getline function
        if(itemName=="exit"){ //if the user typed 'exit'
            break; //break the loop
        }

        cout<<"Enter Protiens(in grams): ";
        cin>>itemProtein;
        cin.ignore();
        if(itemProtein<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Protein grams cannot be negative"<<endl;
            continue; // restart the loop
        }


        cout<<"Enter Carbs(in grams): ";
        cin>>itemCarbs;
        cin.ignore();
        if(itemCarbs<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Carbs grams cannot be negative"<<endl;
            continue; //restart the loop
        }

        cout<<"Enter Fat Content (1 gram of fat=9 calories): ";
        cin>>itemFatGrams;
        cin.ignore();
        if(itemFatGrams<0){ //condition for less than 0(negative numbers)
            cout<<"Error! Fat grams cannot be negative"<<endl;
            continue; //restart the loop
        }

    // creating object of FoodItem class and passing all paramtere except calories
        FoodItem item(itemName,0,itemFatGrams,itemCarbs,itemProtein); 
        int calories= calculateCalories(item); //calling friend function 'calculateCalories' into a variable 
        //Displaying the created food Object
        cout<<"-------------------------------------"<<endl;
        cout<<"DETAILED ITEM"<<endl;
        cout<<"Item Name: "<<item.getName()<<endl;
        cout<<"Item Protien: "<<item.getProtienGrams()<<endl;
        cout<<"Item Carbs: "<<item.getCarbsGram()<<endl;
        cout<<"Calories in "<<item.getName()<<" are: "<<calories<<endl;
        cout<<"-------------------------------------"<<endl;

    }

    return 0;
}
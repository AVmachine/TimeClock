class Employee {
  private:
    int ID[];
    String fName;
    String lName;
    bool isManager;
  public:
    void setFirstName(String firstName = "John"){
      fName = firstName;
    }
    void setLastName(String lastName = "Doe"){
      lName = lastName;
    }
    void setIsManager(bool isMngr = false){
      isManager = isMngr;
    }
    String getFirstName(){
      return this->fName;
    }
    String getLastName(){
      return this->lName;
    }
    bool getIsManager(){
      return this->isManager;
    }
};

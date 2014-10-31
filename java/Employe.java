import java.io.*;

public class Employe{
    // this instance variable is visible for any child class.
    public String name;

    // salary  variable is visible in Employe class only.
    private double salary;

    // The name variable is assigned in the constructor. 
    public Employe (String empName){
        name = empName;
    }

    // The salary variable is assigned a value.
    public void setSalary(double empSal){
        salary = empSal;
    }

    // This method prints the employee details.
    public void printEmp(){
        System.out.println("name  : " + name );
        System.out.println("salary :" + salary);
    }

    public static void main(String args[]){
        Employe empOne = new Employe("Ransika");
        empOne.setSalary(1000);
        empOne.printEmp();
    }
}

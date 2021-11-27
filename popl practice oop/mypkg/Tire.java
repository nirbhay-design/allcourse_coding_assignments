package mypkg;

class NewClass{
    int a = 0;
    public void NewClass(){
        a = 3;
    }
    void method(String s) {
        System.out.println(s);
    }
}

public class Tire {
    public static void main(String args[]){
        System.out.println("Nirbhay sharma");
        NewClass nc = new NewClass();
        nc.method("ravi bhandari");
    }
    public int age;
    public String name;
    public Tire(int age,String name){
        this.age = age;
        this.name = name;
    }

    public void getdet() {
        System.out.println("name is: "+this.name+" age is: "+this.age);
    }
}

package encap;


class A{
    public int b = 3;
    public void print(){
        System.out.println(b);
    }
    public int getb(){
        return b;
    }
}

public class Myclass{
    public static void main(String args[]) {
        A a = new A();
        a.print();
        int myval = a.getb();
        System.out.println(myval);
        System.out.println("nirbhay sharma");
    }
}
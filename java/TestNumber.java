class TestNumber {

    public static void main (String[] args){
        int var1 = 1000;
        int var2 = 1_000;

        System.out.println(var1);
        System.out.println(var2);
        byte var3 = 1;
        byte var4 = 0;
        System.out.println(~var3);
        System.out.println(~var4);
        System.out.println(var3&var4);
        System.out.println(var3^var4);
        System.out.println(var3|var4);
    }
}

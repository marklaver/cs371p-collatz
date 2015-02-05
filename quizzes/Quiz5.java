/*
CS371p: Quiz #5 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following:
    (6 pts)

2
3
466
*/

class Quiz5 {
     static void f (int i, Integer j, int[] a) {
        ++i;
        ++j;
        ++a[1];}

    public static void main (String[] args) {
        int     i = 2;
        Integer j = 3;
        int[]   a = {4, 5, 6};

        f(i, j, a);

        System.out.println(i);
        System.out.println(j);
        for (int v : a)
            System.out.print(v);
        System.out.println();}}

import java.io.*;
import java.util.*;
import java.lang.*;
import java.lang.Object.*;
public class Main {
    public static String And(String num1,String num2)
    {
        int l1=num1.length();
        Integer a=new Integer(10);
        int y=(Integer.parseInt(num1,2)&Integer.parseInt(num2,2));
        String re=a.toString(y,2);
        int l2=re.length();
        String msb=new String();
        for(int i=0;i<(l1-l2);i++)
        {
            msb+="0";
        }
        return msb+re;
    }
    public static int ekcalculate(String x)
    {
        int maxcount=0;
        String[] newarr=x.split(0);
        int len=newarr.length;
        for(int j=0;j<len;j++)
        {
            int countcurr=newarr[j].length();
            if(countcurr!=0 && maxcount<=countcurr)
            {
                maxcount=countcurr;
            }
        }
    return maxcount;
    }
    public static boolean check(String p)
    {
        for(int i=0;i<p.length();i++)
        {
            if(p.charAt(i)!=0)
            {
                return false;
            }
        }
        return true;
    }
    public static int important_fun(String arr[],int n)
    {
        int[] nayaarr=new int[n];
    	for(int i=0;i<n;i++)
        {
            nayaarr[i]=arr[i].replaceAll("#","").replaceAll("x",1).replaceAll("o",0);
        }
        int curexp=0;
        int curgot=0;
        int result=-1;
        for(int i=0;i<n;i++)
        {
            int countcurr=ekcalculate(nayaarr[i]);
            if(curgot<=countcurr)
            {
                curgot=countcurr;
            }
        }

        while(curgot>=curexp)
        {
            curexp+=1;
            String[] temparr=new String[n];
            int newcurgot=0;
            for(int i=0;i<n-1;i++)
            {
                if(check(nayaarr[i+1]))
                {
                    temparr[i]=And(nayaarr[i],nayaarr[i+1]);
                    int newcurcount=ekcalculate(temparr[i]);
                    if(newcurgot<=newcurcount)
                    {
                        newcurgot=newcurcount;
                    }
                }

            }
            curgot=newcurgot;
            for(int i=0;i<n;i++)
            {
                nayaarr[i]=temparr[i];
            }
            if(curgot>=curexp)
            {
                result=curexp+1;
            }
        }
        return result;
    }


    public static void main(String args[] ) throws Exception {
        int n;
        Scanner input=new Scanner(System.in);
        n=input.nextInt();
        String[] arr=new String[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=input.nextLine();
        }
        int ans=important_fun(arr,n);
        System.out.println(ans);
   
   }
}

package class9;
import java.util.Scanner;

public class CanteenMain 
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int ind = 1;

        Student stud[] = new Student[1000];
        int mealPrice = 20;
        
        while(true)
        {
            System.out.println("\nEnter your choice: ");
            System.out.println("1. Add Student Info and Meal Info");
            System.out.println("2. Set Meal Price");
            System.out.println("3. Check Month End Bill");
            System.out.println("4. Exit");

            int n = in.nextInt();

            if(n == 1)
            {
                System.out.print("Enter the students name: ");
                in.nextLine();
                String a = in.nextLine();
                
                System.out.print("Enter the students id: ");
                String b = in.nextLine();
                
                System.out.print("Enter the starting balance: ");
                int c = in.nextInt();
                
                int sum = 0;
                System.out.print("Enter the number of meals the student had each day for 30 days: ");
                for(int i = 0; i < 3; i++)
                {
                	int d = in.nextInt();
                	sum += d;
                }
                
                stud[ind] = new Student(a, b, c, sum);
                
                ind++;
            }
            else if(n == 2)
            {
            	System.out.print("Enter the price of a meal: ");
            	mealPrice = in.nextInt();
            }
            else if(n == 3)
            {
            	System.out.println("Which students info do you want: ");
            	for(int i = 1; i < ind; i++)
            	{
            		System.out.println(i + ". " + stud[i].name);
            	}
            	
            	int b = in.nextInt();
            	stud[b].work(mealPrice);
            }
            else if(n == 4)
                break;
        }
        in.close();
    }
}

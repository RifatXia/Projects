package class9;

public class Student 
{
	public int balance;
	public String name, id;
	public int mealCount;
	
	Student(String a, String b, int c, int sum)
	{
		name = a;
		id = b;
		balance = c;
		mealCount = sum;
	}
	
	public void work(int mealPrice)
	{
		int ans = mealPrice * mealCount;
		
		System.out.println("Name: " + name + "\nID: " + id + "\nTotal meals taken: " + mealCount);
		System.out.println("Balance:          " + balance + "\nTotal:  " + mealPrice + " x " + mealCount + " = " + ans);
		
		balance -= ans;
		
		if(balance >= 0)
			System.out.println("Remaining balance: " + balance);
		else
			System.out.println(name + " needs to pay " + -balance + " to the canteen");
	}
}

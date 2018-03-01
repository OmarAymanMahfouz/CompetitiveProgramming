import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x;
		String s, t ="RAGITM";
		Scanner in = new Scanner(System.in);
		x = in.nextInt();
		int ans[] = new int[6];
		while (x-- != 0)
		{
			Arrays.fill(ans,new Integer(0));
			s = in.next();
			for (int i = 0; i < s.length(); i++)
				for (int j = 0; j < t.length(); j++)
					if (s.charAt(i) == t.charAt(j))
					{
						ans[j]++;
						break;
					}
			int sol = 100000;
			ans[0] /= 2;
			ans[1] /= 3;
			for (int i = 0; i < 6; i++)
				if (sol > ans[i])
					sol = ans[i];
			System.out.println(sol);
		}
	}
}

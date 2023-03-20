import java.util.Scanner;

public class blocos {
	public static void main (String[] args){
		Scanner r = new Scanner(System.in);
		// variaveis
		int t, n, m, a[], best;
		// navegadores
		int x, y, z;
		// auxiliares
		int aux;
		// execucao
		t = r.nextInt();
		while (t-- > 0){
			n = r.nextInt();
			//System.out.println(n);
			a = new int[n];
			m = r.nextInt();
			//System.out.println(m);
			for (x = 0; x < n; x++){
				a[x] = r.nextInt();
				//System.out.println(a[x]);
			}
			best = aux = 0;
			for (x = n-1; x >= 0; x--){
				while (aux+a[x] <= m){
					aux+=a[x];
					best++;
				}
			}
			System.out.println(best);
		}
	}
}

import java.util.Scanner;

public class circo {
	public static void main (String[] args){
		Scanner r = new Scanner(System.in);
		// variaveis
		short n, custo, receita[], best;
		// navegadores
		short x, y, z;
		// auxiliares
		short aux;
		// execucao
		while (r.hasNextShort()){
			n = r.nextShort();
			//System.out.println(n);
			receita = new short[n];
			custo = r.nextShort();
			//System.out.println(custo);
			for (x = 0; x < n; x++){
				receita[x] = r.nextShort();
				//System.out.println(receita[x]);
			}
			best = 0;
			for (x = 0; x < n; x++){
				for (y = 0; y < x; y++){
					aux = 0;
					for(z = y; z < x; z++){
						aux+=receita[z]-custo;
					}
					if (aux > best) best=aux;
				}
			}
			System.out.println(best);
		}
	}
}

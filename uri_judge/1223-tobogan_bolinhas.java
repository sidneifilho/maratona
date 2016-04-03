/// Distancia de um ponto para segmento
import java.util.*;
import java.text.*;
import java.awt.geom.*;
import java.io.*;

public class Main{

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintStream ps = new PrintStream(System.out);
	public static StringTokenizer st;
	public static String line;

	public static boolean readLine()throws Exception{
		line = br.readLine();
		if(line != null){
			st = new StringTokenizer(line);
			return true;
		}
		return false;
	}

	public static void print(String str){
		ps.print(str+"\n");
	}

	public static void main(String[] args) throws Exception{

		int n,l,h,side;
		double diam, x,y, y1, x2, y2,d;
		Line2D.Double aleta = new Line2D.Double();

		while(readLine()){
			n = Integer.valueOf(st.nextElement().toString());

			readLine();
			l = Integer.valueOf(st.nextElement().toString());
			h = Integer.valueOf(st.nextElement().toString());

			readLine();
			y1 = Double.parseDouble(st.nextElement().toString());
			x = Double.parseDouble(st.nextElement().toString());
			y = Double.parseDouble(st.nextElement().toString());
			side = 0;
			diam = l-x;

			for(int i=0;i<n-1;i++){

				readLine();
				y1 = Double.parseDouble(st.nextElement().toString());
				x2 = Double.parseDouble(st.nextElement().toString());
				y2 = Double.parseDouble(st.nextElement().toString());

				if(side == 1){
					aleta.setLine(0, y1, x2, y2);
					diam = Math.min(diam, l-x2);
				}else{
					aleta.setLine(l, y1, x2, y2);
					diam = Math.min(diam, x2);
				}

				d = aleta.ptSegDist(x, y);
				diam = Math.min(diam, d);

				x = x2; y = y2;
				side = 1-side;
			}

			System.out.format("%.2f\n", diam);
		}
	}
}
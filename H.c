#include <iostream>
#include <algorithm>
#include <string>
#define mod 21092013
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string A, B;
int n, m;
short int S[1000002], T[1000002];
int sig[1000002][3], w[1000002];

int main(){

	optimizar_io
	cin >> A >> B;
	m = B.size();
	//convertir A
	for( int i = 0; i < A.size(); i++ ){
		if( A[i] == 'U' )
			n = max( n - 1, 0 );
		else 
			S[++n] =  A[i] == 'L' ? 1 : 0;
	}
	//convertir B
	for( int i = 0; i < m; i++ ){
		if( B[i] == 'U' )
			T[i + 1] = 2;
		else
			T[i + 1] = B[i] == 'L' ? 1 : 0;
	}
	//calcular siguientes para T (0, 1, 2)
	int aux[3] = { 0, 0, 0 };
	for( int i = m; i >= 0; i-- ){
		for( int j = 0; j < 3; j++ )
			sig[i][j] = aux[j];
		aux[ T[i] ] =  i;
 	}
 	//calcular w (DP)
 	for( int i = m; i; i-- ){
 		if( T[i] == 2 ) continue;
 		if( sig[i][0] == 0 && sig[i][1] == 0 ){
 			w[i] = 1;
 			continue;
 		}
 		w[i] = ( w[ sig[i][0] ] + w[ sig[i][1] ] + 1 ) % mod;
 	}
 	/*for( int i = 1; i <= m; i++ )
 		cout << w[i] << " " ;
 	cout << "\n";*/
 	//calcular respuesta
 	int ans = 0, idx = 0;
 	ans = ( w[ sig[0][0] ] + w[ sig[0][1] ] + 1 ) % mod;
 	//cout << ans << "\n";
	for( int i = 0; i < n; i++ ){
		idx = sig[idx][2];
		if( idx == 0 )
			break;
		//cout << idx << " " << sig[idx][0] << " " << sig[idx][1] << "\n";
		ans += S[n - i] == 0 ? w[ sig[idx][1] ] + 1 : w[ sig[idx][0] ] + 1 ;
		ans %= mod;
	}
	cout << ans << "\n";
		
	return 0;

}

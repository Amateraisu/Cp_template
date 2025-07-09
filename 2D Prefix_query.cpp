ll query(const vector<vector<ll>>& P,
         int r1, int c1, int r2, int c2)
{
    // we store P with 1‐based padding, so P[i][j] = sum over [0..i-1][0..j-1]
    return P[r2+1][c2+1]
         - P[r1  ][c2+1]
         - P[r2+1][c1  ]
         + P[r1  ][c1  ];
}


vector<vector<ll>> P0(n+1, vector<ll>(m+1, 0)),
                     P1(n+1, vector<ll>(m+1, 0));
 
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        ll is0 = (type[i][j]=='0');
        ll is1 = 1 - is0;
        // standard 2D prefix sum recurrence
        P0[i+1][j+1] = P0[i][j+1] + P0[i+1][j] - P0[i][j] + is0;
        P1[i+1][j+1] = P1[i][j+1] + P1[i+1][j] - P1[i][j] + is1;
      }
    }

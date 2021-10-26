///////////////////////////////////////////////////////
///////////////////CODIGOS/////////////////////////////
///////////////////////////////////////////////////////

void insertar(int sec[], int ini, int fin) {
  for (int i = ini + 1; i <= fin; i++ ){
    j = i-1;
    x = sec[i];
    while ((x < sec[j]) && (j > 0)){
      sec[j+1] = sec[j] ;
      j--;
    }
    sec[j+1] = x ;
  }
}

void seleccion(int sec[], int n){
  for (int i = 0; i < n-1; i++){
    min = i;
    for (int j = i+1; j < n; j++)
      if (sec[j] < sec[min])
        min = j ;
    x = sec[min] ;
    sec[min] = sec[i] ;
    sec[i] = x ;
  }
}

void bubblesort(int sec[], int n) {
  for (int i = 1; i < n; i++){
    for (int j = n-1; j >= i; j--)
      if (sec[j] < sec[j-1]){
        swap(sec[j-1],sec[j]) ;
    }
  }
}

void shakesort(int sec[], int n) {
  ini = 1 ;
  fin = n-1 ;
  cam = n ;
  while (ini < fin){
    for (int j = fin; j >= ini; j--)
      if (sec[j] < sec[j-1]) {
        swap(sec[j-1],sec[j]) ;
        cam = j ;
      }
    ini = cam + 1 ;
    for (int j = ini; j <= fin; j++)
      if (sec[j] < sec[j-1]) {
        swap(sec[j-1],sec[j]);
        cam = j;
      }
    fin = cam – 1 ;
  }
}

void baja( int i, int sec[], int n ) {
  while ( 2*i <= n ){
    h1 = 2*i;
    h2 = h1 + 1;
    if (h1 == n)
      h = h1
    else if (sec[h1] > sec[h2])
      h = h1
    else h = h2

    if (sec[h] <= sec[i])
      break ;
    else {
      swap(sec[i],sec[h]) ;
      i = h ;
    }
  }
}

void heapsort(int sec[]; int n ) {
  for (int i = n/2; i > 0; i--)
    baja(i, sec, n) ;
  for (int i = n; i > 1; i--) {
    swap(sec[1],sec[i]);
    baja(1,sec,i-1) ;
  }
}

void Qsort(int sec[], ini, fin) {
  int i = ini, f = fin;
  int p = sec[(i+f)/2];
  while (i <= f){
    while (sec[i] < p){
      i++;
    }
    while (sec[f] > p){
      f--;
    }
    if (i <= f) {
      swap(sec[i],sec[f]) ;
      i++ ;
      f-- ;
    }
  }
  if (ini < f) Qsort(sec, ini, f);
  if (i < fin) Qsort(sec, i, fin);
}

void Msort(int sec[],int ini,int fin) {
  if (ini < fin){
    cen = (ini + fin) / 2;
    Msort(sec, ini, cen);
    Msort(sec, cen+1, fin);
    Mezcla(sec, ini, cen, fin);
  }
}

void Mezcla (int sec[],int ini,int cen,int fin){
  i = ini ; j = cen + 1 ; k = ini ;
  while ((i <= cen) && (j <= fin)){
    if (sec[i] < sec[j]){
      aux[k] = sec[i] ;
      i++ ;
    }
    else{
      aux[k] = sec[j] ;
      j++ ;
    }
    k++ ;
  }
  if (i > cen)
    while (j <= fin){
      aux[k] = sec[j] ;
      j++ ; k++ ;
    }
  else
    while (i <= cen){
      aux[k] = sec[i] ;
      i++ ; k++ ;
    }
  for (int k = ini; k <= fin; k++)
  sec[k] = aux[k];
}

void shellsort(int sec[], int n) {
  int del = n;
  while (del > 1){
    del = del / 2 ;
    deltasort(del,sec, n) ;
  }
}
void deltasort( int d, int sec[], int n ) {
  for (int i = d; i < n; i++){
    int x = sec[i] ;
    int j = i ;
    while ((j >= d) && (x < sec[j-d])){
      sec[j] = sec[j-d] ;
      j = j - d ;
    }
    sec[j] = x ;
  }
}

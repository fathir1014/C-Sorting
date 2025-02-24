#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[32m"
#define DEFAULT "\033[0m"

////////////////////////// FUNCTION UNTUK BUBBLE SORT

int angka[100], n;

/// ASCENDING

void bubbleSortAsc() {
  for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
          if (angka[j] > angka[j + 1]) {
              int temp = angka[j];
              angka[j] = angka[j + 1];
              angka[j + 1] = temp;
              for(int k = 0 ; k < n ; k++){
                printf("\033[32m %d ", angka[k]);
              }
              printf("\n");
          }
      }
  }
}

/// DESCENDING

void bubbleSortDesc() {
  for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
          if (angka[j] < angka[j + 1]) { 
              int temp = angka[j];
              angka[j] = angka[j + 1];
              angka[j + 1] = temp;
              for(int k = 0 ; k < n ; k++){
                printf(" \033[32m %d ", angka[k]);
              }
              printf("\n");
          }
      }
  }
}

/////////////////////////////////////////////////////////////////

////////////////////////////////////////////////// SELECTION SORT

/////////////////////////////////// ASCENDING
void selectionSortAsc(int arr[], int n){
  int i, j, posisi, swap;
  for(i = 0; i < (n-1); i++){
    posisi = i;
    for (j = i + 1; j < n; j++){
      if(arr[posisi] > arr[j]){
        posisi = j;
      }
    }
    for(int k = 0 ; k < n ; k++){
      printf("\033[32m%d ", arr[k]);
      // printf("\n");
    }
    printf("\n");

    if(posisi != i){
      swap = arr[i];
      arr[i] = arr[posisi];
      arr[posisi] = swap;
    }
  }
}
/////////////////////////////////////////////// DESCENDING
void selectionSortDesc(int arr[], int n){
  int i, j, posisi, swap;
  for(i = 0; i < (n-1); i++){
    posisi = i;
    for (j = i + 1; j < n; j++){
      if(arr[posisi] < arr[j]){
        posisi = j;
      }
    }
    for(int k = 0 ; k < n ; k++){
      printf("\033[32m%d ", arr[k]);
      // printf("\n");
    }
    printf("\n");

    if(posisi != i){
      swap = arr[i];
      arr[i] = arr[posisi];
      arr[posisi] = swap;
    }
  }
}

///////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////// MERGE SORT

///////////////////////////////////////////////////////////////// ASCENDING
void tampilArray(int arr[], int left, int right) {
  for (int i = left; i <= right; i++)
      printf("\033[32m%d ", arr[i]);
  printf("\n");
}


void mergeAsc(int arr[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArr[n1], rightArr[n2];


  for (i = 0; i < n1; i++)
      leftArr[i] = arr[left + i];
  for (j = 0; j < n2; j++)
      rightArr[j] = arr[mid + 1 + j];

  printf("Sebelum penggabungan : \n");
  tampilArray(arr, left, right);


  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
      if (leftArr[i] <= rightArr[j]) { 
          arr[k] = leftArr[i];
          i++;
      } else {
          arr[k] = rightArr[j];
          j++;
      }
      k++;
  }

 
  while (i < n1) {
      arr[k] = leftArr[i];
      i++;
      k++;
  }


  while (j < n2) {
      arr[k] = rightArr[j];
      j++;
      k++;
  }
  
  printf("Setelah penggabungan : ");
  tampilArray(arr, left, right);
}

void  mergeSortAsc(int arr[], int left, int right) {   
  if (left < right) {
      int mid = left + (right - left) / 2;

      printf("Saat dipisah : \n");
      tampilArray(arr, left, right);

       mergeSortAsc(arr, left, mid);
       mergeSortAsc(arr, mid + 1, right);

      mergeAsc(arr, left, mid, right);
  }
}
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////// DESCENDING
void mergeDesc(int arr[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArr[n1], rightArr[n2];

  for (i = 0; i < n1; i++)
      leftArr[i] = arr[left + i];
  for (j = 0; j < n2; j++)
      rightArr[j] = arr[mid + 1 + j];

  printf("Sebelum penggabungan : \n");
  tampilArray(arr, left, right);


  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
      if (leftArr[i] >= rightArr[j]) { 
          arr[k] = leftArr[i];
          i++;
      } else {
          arr[k] = rightArr[j];
          j++;
      }
      k++;
  }
 
  while (i < n1) {
      arr[k] = leftArr[i];
      i++;
      k++;
  }


  while (j < n2) {
      arr[k] = rightArr[j];
      j++;
      k++;
  }
  
  printf("Setelah penggabungan : ");
  tampilArray(arr, left, right);
}

void  mergeSortDesc(int arr[], int left, int right) {   
  if (left < right) {
      int mid = left + (right - left) / 2;

      printf("Saat dipisah : \n");
      tampilArray(arr, left, right);

       mergeSortDesc(arr, left, mid);
       mergeSortDesc(arr, mid + 1, right);

      mergeDesc(arr, left, mid, right);
  }
}
//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////// QUICK SORT

/////////////////////////////////////////// ASCENDING
void tukar(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void tampilArrayQ(int arr[], int size) {
  for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
}

int partitionAsc(int arr[], int low, int high, int size) {
  int pivot = arr[high];  
  int i = (low - 1);  

  for (int j = low; j < high; j++) {
     
      if (arr[j] < pivot) {
          i++;
          tukar(&arr[i], &arr[j]);
          tampilArrayQ(arr, size); 
      }
  }

  tukar(&arr[i + 1], &arr[high]);
  tampilArrayQ(arr, size); 
  return (i + 1);
}

// Fungsi QuickSort
void quickSortAsc(int arr[], int low, int high, int size) {
  if (low < high) {
 
      int pi = partitionAsc(arr, low, high, size);
      quickSortAsc(arr, low, pi - 1, size);
      quickSortAsc(arr, pi + 1, high, size);
  }
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////// DESCENDING

void tampilarrayQ(int arr[], int size) {
  for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
}


int partitionDesc(int arr[], int low, int high, int size) {
  int pivot = arr[high];  
  int i = (low - 1);  

  for (int j = low; j < high; j++) {

      if (arr[j] > pivot) {
          i++;
          tukar(&arr[i], &arr[j]);
          tampilArrayQ(arr, size);
      }
  }

  tukar(&arr[i + 1], &arr[high]);
  tampilArrayQ(arr, size); 
  return (i + 1);
}

void quickSortDesc(int arr[], int low, int high, int size) {
  if (low < high) {

      int pi = partitionDesc(arr, low, high, size);

      quickSortDesc(arr, low, pi - 1, size);
      quickSortDesc(arr, pi + 1, high, size);
  }
}


int main(){

char ulang[30];
char ulangSort[30];
int pilihan;
int pil_asc_desc;


awal:

printf("\t\t======== MENU SORTING ========\n\n");
printf("1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Quick Sort\n5. Selection Sort\n");

printf("Masukan nomor untuk memilih sorting : ");
scanf("%d", &pilihan);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// BUBBLE SORT
if(pilihan == 1){
  awalBubble:
  printf("\n\n========= BUBBLE SORT =========\n\n");
  printf("1. Ascending code\n2. Descending code\n");
  printf("Masukan nomor untuk memilih : ");
  scanf("%d", &pil_asc_desc);

  switch(pil_asc_desc){


    case 1:
      printf("======== ASCENDING CODE ========\n\n");
    
      printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    printf("Masukkan %d angka: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &angka[i]); 
    }

    printf("\nSebelum Sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n\n");
    // Sorting ascending
    bubbleSortAsc();
    printf("\n\n \033[0m Setelah Sorting : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", angka[i]);
    }

goto kesini;

    break;
    case 2:
      printf("======== DESCENDING CODE ========\n\n");
      
      printf("Masukkan jumlah data: ");
      scanf("%d", &n);
  
      printf("Masukkan %d angka: \n", n);
      for (int i = 0; i < n; i++) {
          scanf("%d", &angka[i]); 
      }
  
      printf("\nSebelum Sorting: \n");
      for (int i = 0; i < n; i++) {
          printf("%d ", angka[i]);
      }
      printf("\n\n");

      bubbleSortDesc();
      printf("\n\n\033[0mSetelah Sorting Descending : \n");
      for (int i = 0; i < n; i++) {
          printf("%d ", angka[i]);
      }

      goto kesini;

    break;

    default:
    getchar();
    printf("SALAH INPUT, ULANG!!!\n");
    printf("Ketik 'ya' untuk mengulang : ");

    fgets(ulangSort, sizeof(ulangSort), stdin);
    ulangSort[strcspn(ulangSort, "\n")] = 0;


    if(strcmp(ulangSort, "ya") == 0){
      goto awalBubble;
    }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////// INSERTION SORT
else if(pilihan == 2){

  awalInsert:

  printf("\n========= INSERTION SORT =========\n\n");
  printf("1. Ascending code\n2. Descending code\n");

  printf("Masukan nomor untuk memilih : ");
  scanf("%d", &pil_asc_desc);

  switch(pil_asc_desc){
    case 1:
      printf("======== ASCENDING CODE ========\n\n");
    
      printf("Masukan jumlah data : ");
      scanf("%d", &n);
      printf("Masukan angka sebanyak %d angka : \n", n);
      for(int k = 0 ; k < n ; k++){
        scanf("%d", &angka[k]);
      }

  printf("Sebelum sorting : ");
  for (int k = 0 ; k < n ; k++){
    printf("%d ", angka[k]);
  }
  printf("\n");

	for(int i=1; i<n; i++){
		for(int j=i; j>0 && angka[j]<angka[j-1]; j--){
			int temp=angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
      for(int k = 0 ; k < n ; k++){
        printf("\033[32m%d ", angka[k]);
      }
      printf("\n");
		}
	}

  printf("\n\033[0mSetelah sorting : ");
  for(int i=0; i<n; i++){
		printf("%d ", angka[i]);
	}
  goto kesini;

    break;

    case 2:
      printf("======== DESCENDING CODE ========\n\n");
      
      printf("Masukan jumlah data : ");
      scanf("%d", &n);
      printf("Masukan angka sebanyak %d angka : \n", n);
      for(int k = 0 ; k < n ; k++){
        scanf("%d", &angka[k]);
      }

  printf("Sebelum sorting : ");
  for (int k = 0 ; k < n ; k++){
    printf("%d ", angka[k]);
  }
  printf("\n");

	for(int i=1; i<n; i++){
		for(int j=i; j>0 && angka[j] > angka[j-1]; j--){
			int temp=angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
      for(int k = 0 ; k < n ; k++){
        printf("\033[32m%d ", angka[k]);
      }
      printf("\n");
		}
	}

  printf("\n\033[0mSetelah sorting : ");
  for(int i=0; i<n; i++){
		printf("%d ", angka[i]);
	}
  goto kesini;

    break;

    default:
    getchar();
    printf("SALAH INPUT, ULANG!!!\n");
    printf("Ketik 'ya' untuk mengulang : ");

    fgets(ulangSort, sizeof(ulangSort), stdin);
    ulangSort[strcspn(ulangSort, "\n")] = 0;

    if(strcmp(ulangSort, "ya") == 0){
      goto awalInsert;
    }
  }
}
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////// MERGE SORT
else if(pilihan == 3){
  awalMerge:
  printf("\n========= MERGE SORT =========\n\n");
  printf("1. Ascending code\n2. Descending code\n");
  printf("Masukan nomor untuk memilih : ");
  scanf("%d", &pil_asc_desc);

  switch(pil_asc_desc){
    case 1:
      printf("======== ASCENDING CODE ========\n\n");

      int arr[100], n, i;
    
      printf("Masukan jumlah data : ");
      scanf("%d", &n);
  
   
      printf("Masukan angka sebanyak %d angka :\n ", n);
      for (i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
      }
  
      mergeSortAsc(arr, 0, n - 1);

      tampilArray(arr, 0, n - 1);
      goto kesini;

    break;
    case 2:
      printf("======== DESCENDING CODE ========\n\n");
    
      printf("Masukan jumlah data : ");
      scanf("%d", &n);
  
   
      printf("Masukan angka sebanyak %d angka :\n ", n);
      for (i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
      }
  
      mergeSortDesc(arr, 0, n - 1);
  
      tampilArray(arr, 0, n - 1);
goto kesini;

    break;

    default:
    getchar();
    printf("SALAH INPUT, ULANG!!!\n");
    printf("Ketik 'ya' untuk mengulang : ");

    fgets(ulangSort, sizeof(ulangSort), stdin);
    ulangSort[strcspn(ulangSort, "\n")] = 0;

    if(strcmp(ulangSort, "ya") == 0){
      goto awalMerge;
    }
  }
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////// QUICK SORT

else if(pilihan == 4){
  awalQuick:
  printf("\n========= QUICK SORT =========\n\n");
  printf("1. Ascending code\n2. Descending code\n");
  printf("Masukan nomor untuk memilih : ");
  scanf("%d", &pil_asc_desc);

  switch(pil_asc_desc){
    case 1:
    { 
      printf("======== ASCENDING CODE ========\n\n");
        int n;
    
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    
    int arr[n]; 

    printf("Masukkan angka: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSortAsc(arr, 0, n - 1, n);

    printf("Hasil akhir: ");
    tampilArrayQ(arr, n);
goto kesini;
  
    break;
  }
    case 2:{ 
      printf("======== DESCENDING CODE ========\n\n");
      printf("Masukkan jumlah elemen: ");
      scanf("%d", &n);
      
      int arr[n]; // Menggunakan array statis
  
      printf("Masukkan angka: ");
      for (int i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
      }
  
      quickSortDesc(arr, 0, n - 1, n);
  
      printf("Hasil akhir: ");
      tampilArrayQ(arr, n);
goto kesini;
    
    break;
    }

    default:
    getchar();
    printf("SALAH INPUT, ULANG!!!\n");
    printf("Ketik 'ya' untuk mengulang : ");

    fgets(ulangSort, sizeof(ulangSort), stdin);
    ulangSort[strcspn(ulangSort, "\n")] = 0;

    if(strcmp(ulangSort, "ya") == 0){
      goto awalQuick;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////// SELECTION SORT
else if(pilihan == 5){
  int array[100], n, i;
  awalSelect:
  
  printf("\n========= SELECTION SORT =========\n\n");
  printf("1. Ascending code\n2. Descending code\n");
  printf("Masukan nomor untuk memilih : ");
  scanf("%d", &pil_asc_desc);

  switch(pil_asc_desc){
    case 1:
      printf("======== ASCENDING CODE ========\n\n");
    
      printf("Masukkan banyaknya jumlah data: ");
      scanf("%d", &n);
    
      printf("Masukkan data sebanyak %d :\n", n);
      for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
      }
      printf("Data sebelum diurutkan : ");
      for(int i = 0 ; i < n ; i++){
        printf("%d ", array[i]);
        
      }
    printf("\n");
    
      selectionSortAsc(array, n);
    
      printf("\n\033[0mHasil pengurutan sebagai berikut:\n");
      for(i = 0; i < n; i++){
        printf("%d ", array[i]);
      }
      printf("\n");
goto kesini;

    break;
    case 2:
      printf("======== DESCENDING CODE ========\n\n");
      
      printf("Masukkan banyaknya jumlah data: ");
      scanf("%d", &n);
    
      printf("Masukkan data sebanyak %d :\n", n);
      for(i = 0; i < n; i++){
        scanf("%d", &array[i]);
      }
      printf("Data sebelum diurutkan : ");
      for(int i = 0 ; i < n ; i++){
        printf("%d ", array[i]);
        
      }
    printf("\n");
    
      selectionSortDesc(array, n);
    
      printf("\n\033[0mHasil pengurutan sebagai berikut:\n");
      for(i = 0; i < n; i++){
        printf("%d ", array[i]);
      }
      printf("\n");
goto kesini;

    break;

    default:
    getchar();
    printf("SALAH INPUT, ULANG!!!\n");
    printf("Ketik 'ya' untuk mengulang : ");

    fgets(ulangSort, sizeof(ulangSort), stdin);
    ulangSort[strcspn(ulangSort, "\n")] = 0;

    if(strcmp(ulangSort, "ya") == 0){
      goto awalSelect;
    }
  }
}
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
else{
  printf("\nINPUT SALAH!!!\n\n");
  getchar();
  printf("ketik 'ya' untuk mengulang : ");
  fgets(ulang, sizeof(ulang), stdin);
  ulang[strcspn(ulang, "\n")] = 0;


  if(strcmp(ulang, "ya") == 0){
    system("cls");
    goto awal;
  }
}
return 0;

kesini:
printf("\napakah anda ingin mengulang lagi? \n");
printf("Ketik 'ya' jika iya : ");
getchar();
fgets(ulang, sizeof(ulang), stdin);
ulang[strcspn(ulang, "\n")] = 0;


if(strcmp(ulang, "ya") == 0){
  system("cls");
  goto awal;
}
else{
  system("cls");
}

  return 0;
}
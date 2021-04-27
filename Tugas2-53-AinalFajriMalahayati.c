#include <stdio.h>

//fungsi untuk menghitung pembayaran yang dilakukan oleh user
int pembayaran(int total_belanja, int uang, int uang_kembali, int uang_kurang, int uang_tambah)
{
  if(uang>=total_belanja)
  {
    uang_kembali=uang-total_belanja;
    printf("\t\t\tUang kembali\t\t\t: %d", uang_kembali);
  }
  if(uang<total_belanja)
  {
    uang_kurang = total_belanja-uang;
    //uang_kembali=uang_tambah-uang_kurang;
    printf("\n\t\t\tUang Anda kurang\t\t: %d\n", uang_kurang);
    printf("\t\t\tMasukkan uang tambahan\t\t: "); scanf("%d", &uang_tambah);
    uang_kembali=uang_tambah-uang_kurang;
    printf("\t\t\tUang kembali\t\t\t: %d", uang_kembali);
  }

  return uang_kembali;
}

//fungsi yang berisi tampilan menu untuk ditampilkan jika user memilih pilihan 1
int opsi1()
{
  printf("\t\t\t+------------------------------------------+\n");
  printf("\t\t\t| no  | nama barang      |      harga      |\n");
  printf("\t\t\t+------------------------------------------+\n");
  printf("\t\t\t|  1  | Maxi             |      35000      |\n");
  printf("\t\t\t|  2  | Me-O             |      17000      |\n");
  printf("\t\t\t|  3  | Bolt             |      15000      |\n");
  printf("\t\t\t|  4  | Royal Canin      |      54000      |\n");
  printf("\t\t\t|  5  | Proplan          |      48000      |\n");
  printf("\t\t\t|  6  | Friskies         |      21000      |\n");
  printf("\t\t\t|  7  | Whiskas          |      26000      |\n");
  printf("\t\t\t+------------------------------------------+\n");
  printf("\t\t\tTekan enter untuk pilihan selanjutnya.....");
  getchar();
  printf("\n");
}

int main()
{
    //1. Deklarasi variabel dan struct
      int no_barang, jumlah_barang, pilihan, jumlah, i, uang, uang_kembali,uang_kurang, uang_tambah;
      int total_belanja=0;
      char jawab;

    typedef struct Menu
    {
      int no_barang;
      int harga_barang;
      char *nama_barang;
    } Mn;
    Mn menu[6];

    menu[0].no_barang= 1; menu[0].nama_barang= "Maxi"; menu[0].harga_barang= 35000;
    menu[1].no_barang= 2; menu[1].nama_barang= "Me-O"; menu[1].harga_barang= 17000;
    menu[2].no_barang= 3; menu[2].nama_barang= "Bolt"; menu[2].harga_barang= 15000;
    menu[3].no_barang= 4; menu[3].nama_barang= "Royal Canin"; menu[3].harga_barang= 54000;
    menu[4].no_barang= 5; menu[4].nama_barang= "Proplan"; menu[4].harga_barang= 48000;
    menu[5].no_barang= 6; menu[5].nama_barang= "Friskies"; menu[5].harga_barang= 21000;
    menu[6].no_barang= 7; menu[6].nama_barang= "Whiskas"; menu[6].harga_barang= 26000;

    //1a. Beranda
    printf("\t\t\t+===========================================================+\n");
    printf("\t\t\t|                          CATSHOP                          |\n");
    printf("\t\t\t+===========================================================+\n");
    printf("\t\t\t******************SELAMAT DATANG DI CATSHOP******************\n");

    do
    {
        printf("\n");
        printf("\t\t\t1. Menu\n");
        printf("\t\t\t2. Pembayaran\n");
        printf("\t\t\t3. Keluar\n");

        printf("\t\t\tMasukkan pilihan anda: "); scanf("%d", &pilihan);
        while(pilihan<1 || pilihan>3)
        {
            printf("\t\t\tMaaf pilihan anda tidak sesuai\n");
            printf("\t\t\tMasukkan pilihan anda: "); scanf("%d", &pilihan);
        }

    //2. User memilih 
      //2a. User memilih pilihan pertama-menu. outputnya tabel menu.
        if(pilihan==1)
            opsi1();

      //2b. User memilih pilihan kedua-order&bayar
        if(pilihan==2)
        {
          do
          {
              printf("\t\t\tMasukkan nomor barang yang ingin anda beli: "); scanf("%d", &no_barang);
              while(no_barang<1 || no_barang>7)
              {
                  printf("\t\t\tMasukkan nomor barang yang ingin anda beli: "); scanf("%d", &no_barang);
              }
              printf("\t\t\tMasukkan jumlah barang yang Anda beli: "); scanf("%d", &jumlah_barang);
              jumlah=jumlah_barang*menu[no_barang-1].harga_barang;
              total_belanja=total_belanja+jumlah;

              printf("\n\n\t\t\tApakah anda ingin belanja lagi(Y/T)?: "); scanf("%c", &jawab);

              while(jawab!='Y' && jawab!='T')
              {
                  printf("\t\t\tKarakter yang anda masukkan tidak sesuai\n");
                  printf("\n\n\t\t\tApakah anda ingin belanja lagi(Y/T)?: "); scanf("%c", &jawab);

              }
              printf("\n");
          }while(jawab=='Y');

          printf("\n\t\t\tTotal belanja anda adalah\t: %d", total_belanja);
          printf("\n\t\t\tMasukkan uang anda              : "); scanf("%d", &uang);
          pembayaran(total_belanja, uang, uang_kembali, uang_kurang, uang_tambah);
          break;
        }

        if(pilihan==3)
        {
          break;
        }

    //3. Menu exit
    } while(getchar());

    return 0;
}

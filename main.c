#include <stdio.h>
#include <stdlib.h>

typedef char string[50];

int main(int argc, char *argv[])
{
	/*
	catatan: belum di kerjakan Case 7 belum selesai
	*/

	// menu
	int menu, login = 0, logout = 0, pembayaran = 0, perbandingan = 0;

	// Login
	string user, pass;
	int matchUser = 0, matchpass = 0;

	// pesanan
	int input, inpt_kanji, inpt_telur, inpt_gula; // inpt_kanji == input kanji
	int kanji = 0, telur = 0, gula = 0;
	int match_kanji = 0, match_telur = 0, match_gula = 0;

	// Pembayaran
	int hg_kanji = 4000, hg_telur = 2500, hg_gula = 7000; // hg_kanji == harga kanji
	int thg_kanji, thg_gula, thg_telur;					  // thg_kanji == total harga kanji
	int total_semua, bayar, kembalian;
	int match_semua = 0;

	// logout
	string keluar;

	// Diskon [Tugas]
	int i, diskon, angka_random, tebakan, lebih5, kurang5, potongan_diskon;
	int match_diskon = 0, a = 0;

	// histori [Tugas]
	int histroi_kanji = 0, histroi_telur = 0, histroi_gula = 0;

	// login [Bonus]
	string random, captcha;
	int match_captcha = 0, angka_random1, angka_random2;
	char huruf1, huruf2, huruf3, huruf4, huruf5, huruf6, huruf7;

	srand(time(NULL));

	do
	{
		system("cls");
		printf("\n\tUnguided LOOP I");
		printf("\n [1]. Login");
		printf("\n [2]. Input Pesanan");
		printf("\n [3]. Pembayaran");
		printf("\n [4]. Logout");
		printf("\n [0]. Exit");

		printf("\n\n\n [5]. Diskon Time [Tugas]");
		printf("\n [6]. Histori [Tugas]");
		printf("\n [7]. Login (Bonus)");

		printf("\n >>> ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1: // LOGIN
		{
			if (login == 0)
			{
				printf("\t<===== LOGIN =====>");
				printf("\nUsername	: ");
				fflush(stdin);
				gets(user);
				printf("Password	: ");
				fflush(stdin);
				gets(pass);

				if (strcmp(user, "UserA") == 0 && strcmp(pass, "PasswordA") == 0)
				{
					printf("\n\tLOGIN Berhasil !");
					login = login + 1;
				}
				else if (strcmp(pass, "PasswordA") == 0)
				{
					while (matchUser != 1)
					{
						printf("\n\tUsername Salah !");
						printf("\nUsername  : ");
						fflush(stdin);
						gets(user);

						if (strcmp(user, "UserA") == 0)
						{
							matchUser++;
						}
					}
					printf("\n\tLOGIN Berhasil !");
					login = login + 1;
				}
				else if (strcmp(user, "UserA") == 0)
				{
					while (matchpass != 1)
					{
						printf("\n\tPassword Salah !");
						printf("\nPassword  : ");
						fflush(stdin);
						gets(pass);

						if (strcmp(pass, "PasswordA") == 0)
						{
							matchpass++;
						}
					}
					printf("\n\tLOGIN Berhasil !");
					login = login + 1;
				}
				else
				{
					while (matchUser != 1)
					{
						printf("\n\tUsername Salah !");
						printf("\nUsername  : ");
						fflush(stdin);
						gets(user);

						if (strcmp(user, "UserA") == 0)
						{
							matchUser++;
						}
					}
					while (matchpass != 1)
					{
						printf("\n\tPassword Salah !");
						printf("\nPassword  : ");
						fflush(stdin);
						gets(pass);

						if (strcmp(pass, "PasswordA") == 0)
						{
							matchpass++;
						}
					}
					printf("\n\tLOGIN Berhasil !");
					login = login + 1;
				}
			}
			else
			{
				printf("\n\tSudah Login !");
			}
		}
		break;

		case 2: // Input Pesanan
		{
			if (login == 1)
			{
				do
				{
					system("cls");
					printf("\n\tInput Pesanan");
					printf("\n[1].Kanji		= %d kg", kanji);
					printf("\n[2].Telur		= %d butir", telur);
					printf("\n[3].Gula		= %d kg", gula);
					printf("\n\n[0].Main Menu");
					printf("\n\n >>> ");
					scanf("%d", &input);

					switch (input)
					{
					case 1:
					{
						printf("\n Masukan jumlah Kanji	: ");
						scanf("%d", &inpt_kanji);
						if (inpt_kanji > 0)
						{
							printf("\n\tBerhasil menambahkan pesanan Kanji");
							kanji = kanji + inpt_kanji;
							pembayaran = pembayaran + 1;
						}
						else
						{
							while (match_kanji != 1)
							{
								printf("\n inputan harus lebih dari 0");
								printf("\n Masukan jumlah pesanan : ");
								scanf("%d", &inpt_kanji);
								if (inpt_kanji > 0)
								{
									kanji = kanji + inpt_kanji;
									match_kanji++;
								}
							}
							printf("\n\n\tBerhasil menambahkan pesanan kanji");
							pembayaran = pembayaran + 1;
						}
					}
					break;

					case 2:
					{
						printf("\n Masukan jumlah Telur	: ");
						scanf("%d", &inpt_telur);
						if (inpt_telur > 0)
						{
							telur = telur + inpt_telur;
							printf("\n\tBerhasil menambahkan pesanan Telur");
							pembayaran = pembayaran + 1;
						}
						else
						{
							while (match_telur != 1)
							{
								printf("\n inputan harus lebih dari 0");
								printf("\n Masukan jumlah pesanan : ");
								scanf("%d", &inpt_telur);
								if (inpt_telur > 0)
								{
									telur = telur + inpt_telur;
									inpt_telur++;
								}
							}
							printf("\n\n\tBerhasil menambahkan pesanan Telur");
							pembayaran = pembayaran + 1;
						}
					}
					break;

					case 3:
					{
						printf("\n Masukan jumlah Gula	: ");
						scanf("%d", &inpt_gula);
						if (inpt_gula > 0)
						{
							gula = gula + inpt_gula;
							printf("\n\tBerhasil menambahkan pesanan Gula");
							pembayaran = pembayaran + 1;
						}
						else
						{
							while (match_gula != 1)
							{
								printf("\n inputan harus lebih dari 0");
								printf("\n Masukan jumlah pesanan : ");
								scanf("%d", &inpt_gula);
								if (inpt_gula > 0)
								{
									gula = gula + inpt_gula;
									inpt_gula++;
								}
							}
							printf("\n\n\tBerhasil menambahkan pesanan Gula");
							pembayaran = pembayaran + 1;
						}
					}
					break;

					case 0:
						// total harga barang//
						thg_kanji = kanji * hg_kanji;
						thg_telur = telur * hg_telur;
						thg_gula = gula * hg_gula;

						// totalsemua//
						total_semua = thg_kanji + thg_telur + thg_gula;
						diskon = (total_semua * 3) / 100;

						printf("\n\tPesanan akan diproses");
						break;

					default:
						printf("\n\tbahan tidak ada");
						break;
					}
					getch();
				} while (input != 0);
			}
			else
			{
				printf("\n\tBelum Login");
			}
		}
		break;

		case 3: // Pembayaran
		{
			if (login == 1)
			{
				if (pembayaran > 0)
				{
					system("cls");
					if (match_diskon == 1)
					{
						printf("\n\tPembayaran\n");
						printf("\nKanji		= %d kg", kanji);
						printf("\nTelur		= %d butir", telur);
						printf("\nGula		= %d kg", gula);
						printf("\n=======================");
						printf("\n Total	= Rp. %d.00", potongan_diskon);
						printf("\n Masukan inputan uang	: Rp. ");
						scanf("%d", &bayar);
						if (bayar < potongan_diskon)
						{
							while (match_semua != 1)
							{
								printf("\n\tUang anda kurang !");
								printf("\n Masukan inputan uang	: ");
								scanf("%d", &bayar);
								if (potongan_diskon < bayar)
								{
									kembalian = bayar - potongan_diskon;
									printf("\n\n Kembalian	: Rp. %d.00", kembalian);
									printf("\n Pembayaran berhasil");
									match_semua = match_semua + 1;
								}
								else if (potongan_diskon == bayar)
								{
									printf("\n\nPembayaran berhasil");
									match_semua = match_semua + 1;
								}
								else
								{
								}
							}
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							match_diskon = 0, a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
						else if (bayar > potongan_diskon)
						{
							kembalian = bayar - potongan_diskon;
							printf("\n\n Kembalian	: Rp. %d.00", kembalian);
							printf("\n Pembayaran berhasil");
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							match_diskon = 0, a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
						else
						{
							printf("\n Pembayaran berhasil");
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							match_diskon = 0, a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
					}
					else
					{
						printf("\n\tPembayaran\n");
						printf("\nKanji		= %d kg", kanji);
						printf("\nTelur		= %d kg", telur);
						printf("\nGula		= %d kg", gula);
						printf("\n=======================");
						printf("\n Total	= Rp. %d.00", total_semua);
						printf("\n Masukan inputan uang	: Rp. ");
						scanf("%d", &bayar);

						if (bayar < total_semua)
						{
							while (match_semua != 1)
							{
								printf("\n\tUang anda kurang !");
								printf("\n Masukan inputan uang	: ");
								scanf("%d", &bayar);
								if (total_semua < bayar)
								{
									kembalian = bayar - total_semua;
									printf("\n\n Kembalian	: Rp. %d.00", kembalian);
									printf("\n Pembayaran berhasil");
									match_semua = match_semua + 1;
								}
								else if (total_semua == bayar)
								{
									printf("\n\nPembayaran berhasil");
									match_semua = match_semua + 1;
								}
								else
								{
								}
							}
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
						else if (bayar > total_semua)
						{
							kembalian = bayar - total_semua;
							printf("\n\n Kembalian	: Rp. %d.00", kembalian);
							printf("\n Pembayaran berhasil");
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
						else
						{
							printf("\n Pembayaran berhasil");
							histroi_kanji = histroi_kanji + kanji;
							histroi_gula = histroi_gula + gula;
							histroi_telur = histroi_telur + telur;

							// Menghapus || mengembaliakn isi variabel menjadi 0 kembali
							a = 0, angka_random = 0, i = 0, pembayaran = 0, kanji = 0, telur = 0, gula = 0, thg_kanji = 0, thg_telur = 0, thg_gula = 0, total_semua = 0, kembalian = 0;
						}
					}
				}
				else
				{
					printf("\n\tTidak ada pesanan !");
				}
			}
			else
			{
				printf("\n\tBelum Login");
			}
		}
		break;

		case 4: // Logout
		{
			if (login == 1)
			{
				if (pembayaran > perbandingan)
				{
					printf("\n\tmasih ada pesanan yang belum dibayar !");
				}
				else
				{
					printf("\n\tLOGOUT");
					printf("\n Apakah yakin ingin Logout (yes / no ) : ");
					fflush(stdin);
					gets(keluar);

					if (strcmpi(keluar, "yes") == 0)
					{
						printf("\n\tLogout berhasil");
						histroi_gula = 0;
						histroi_kanji = 0;
						histroi_telur = 0;
						login = 0;
						match_captcha = 0;
					}
					else
					{
						printf("\n\tLogout dibatalkan");
					}
				}
			}
			else
			{
				printf("\n\tBelum Login");
			}
		}
		break;

		case 5: // Diskon [Tugas]
		{
			if (login == 1)
			{
				if (pembayaran > 0)
				{
					if (i != 3)
					{
						system("cls");
						angka_random = (rand() % (0 - 100 + 1)) + 1;

						printf("\n\tTebak Angka");
						printf("\n Angka random	: %d", angka_random);

						while (i < 3)
						{
							for (i = 0; i < 3; i++)
							{
								// membuat hint "Sedikit Lagi"
								lebih5 = angka_random + 5;
								kurang5 = angka_random - 5;
								printf("\n masukan tebakan	: ");
								scanf("%d", &tebakan);

								if (tebakan == angka_random)
								{
									printf("\n\tAngka Random = %d", angka_random);
									printf("\n\tTebakan Benar");
									printf("\n\ttotal discount	: Rp. %d.00", diskon);

									potongan_diskon = total_semua - diskon;
									match_diskon++;
									i = 4;
								}
								else
								{
									if (tebakan <= lebih5 && tebakan >= kurang5)
									{
										printf("\n\tSedikit lagi");
										a = a + 1;

										if (a >= 3)
										{
											printf("\n\n\tDiskon hangus");
										}
									}
									else
									{
										if (tebakan > 100)
										{
											printf("\n\tTebakan diluar batas");
											a = a + 1;

											if (a >= 3)
											{
												printf("\n\n\tDiskon hangus");
											}
										}

										else
										{
											printf("\n\ttebakan masih jauh");
											a = a + 1;

											if (a >= 3)
											{
												printf("\n\n\tDiskon hangus");
											}
										}
									}
								}
							}
						}
					}
					else
					{
						printf("\n\tDiskon sudah diambil");
					}
				}
				else
				{
					printf("\n\ttidak ada pesanan !");
				}
			}
			else
			{
				printf("\n\tanda belum Login");
			}
		}
		break;

		case 6: // histroi [Tugas]
		{
			if (login == 1)
			{
				printf("\n\t\tHistori Pembelian");
				printf("\n\t=============================");
				printf("\n\tKanji	: %d kg", histroi_kanji);
				printf("\n\tTelur	: %d butir", histroi_telur);
				printf("\n\tGula	: %d kg", histroi_gula);
				printf("\n\t=============================");
			}
			else
			{
				printf("\n\tanda belum Login");
			}
		}
		break;

		case 7: // login [Bonus]
		{

			if (login == 0)
			{
				printf("\t<===== LOGIN =====>");
				printf("\n Username	: ");
				fflush(stdin);
				gets(user);
				printf(" Password	: ");
				fflush(stdin);
				gets(pass);

				if (strcmp(user, "UserA") == 0 && strcmp(pass, "PasswordA") == 0)
				{
					login = login + 1;
				}
				else if (strcmp(pass, "PasswordA") == 0)
				{
					while (matchUser != 1)
					{
						printf("\n\tUsername Salah !");
						printf("\n Username  : ");
						fflush(stdin);
						gets(user);

						if (strcmp(user, "UserA") == 0)
						{
							matchUser++;
						}
					}
					login = login + 1;
				}
				else if (strcmp(user, "UserA") == 0)
				{
					while (matchpass != 1)
					{
						printf("\n\tPassword Salah !");
						printf("\n Password  : ");
						fflush(stdin);
						gets(pass);

						if (strcmp(pass, "PasswordA") == 0)
						{
							matchpass++;
						}
					}
					login = login + 1;
				}
				else
				{
					while (matchUser != 1)
					{
						printf("\n\tUsername Salah !");
						printf("\n Username  : ");
						fflush(stdin);
						gets(user);

						if (strcmp(user, "UserA") == 0)
						{
							matchUser++;
						}
					}
					while (matchpass != 1)
					{
						printf("\n\tPassword Salah !");
						printf("\n Password  : ");
						fflush(stdin);
						gets(pass);

						if (strcmp(pass, "PasswordA") == 0)
						{
							matchpass++;
						}
					}
					login = login + 1;
				}
			}
			else
			{
				printf("\n\tSudah Login !");
			}

			// Membuat CAPTCHA
			while (match_captcha != 1)
			{
				angka_random1 = (rand() % (0 - 9 + 1)) + 1;
				angka_random2 = (rand() % (0 - 9 + 1)) + 1;
				huruf1 = 'A' + (rand() % 26);
				huruf2 = 'a' + (rand() % 26);
				huruf3 = 'a' + (rand() % 26);
				huruf4 = 'A' + (rand() % 26);
				huruf5 = 'a' + (rand() % 26);
				huruf6 = 'A' + (rand() % 26);
				huruf7 = 'a' + (rand() % 26);

				sprintf(random, "%d%c%c%d%c%c%c%c%C", angka_random1, huruf1, huruf2, angka_random2, huruf3, huruf4, huruf5, huruf6, huruf7);

				printf("\n CAPTCHA		: %s", random);
				printf("\n CAPTCHA		: ");
				fflush(stdin);
				gets(captcha);

				if (strcmpi(captcha, random) == 0)
				{
					printf("\n\t LOGIN Berhasil");
					match_captcha++;
				}
				else
				{
					printf("\n\t CAPTCHA Salah ! \n");
				}
			}
		}
		break;

		case 0:
		{
			if (login == 1)
			{
				printf("\n log out first !");
			}
			else
			{
				logout++;
				printf("\nAntonius Hardiantono Karurukan | 220711690 | Kelas A");
			}
		}
		break;

		default:
			printf("\n\tMenu tidak ada !");
			break;
		}
		getch();
	} while (logout != 1);
	return 0;
}

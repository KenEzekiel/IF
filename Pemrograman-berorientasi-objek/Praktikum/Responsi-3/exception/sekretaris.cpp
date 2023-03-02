#include "sekretaris.h"
#include "memo.h"
#include <string>
#include <iostream>

using namespace std;

/*
			Membuat objek Sekretaris dengan nilai kertas dan tinta
			default. Besar energi awal adalah ENERGI_MAX
		*/
Sekretaris::Sekretaris()
{
	kertas = KERTAS_DEFAULT;
	tinta = TINTA_DEFAULT;
	energi = ENERGI_MAX;
	memo = new Memo[100];
	memoLength = 0;
}
/*
	Membuat objek Sekretaris dengan nilai kertas dan tinta
	sesuai yang diberikan. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris(int kertas, int tinta)
{
	this->kertas = kertas;
	this->tinta = tinta;
	this->energi = ENERGI_MAX;
	this->memo = new Memo[100];
	this->memoLength = 0;
}
/*
	Dealokasi variabel-variabel yang perlu didealokasi.
	Jika tidak perlu, hapus metode ini.
*/
Sekretaris::~Sekretaris()
{
	delete[] this->memo;
}

/*
	Membuat memo dengan isi sesuai yang diberikan. Metode ini
	menggunakan metode pakaiKertas, pakaiTinta, dan pakaiEnergi.
	Untuk membuat 1 memo akan menghabiskan 1 kertas, 1 energi,
	dan tinta sebanyak jumlah karakter pesan.

	Ada beberapa penyebab memo gagal dibuat, yaitu:
	- Jika kertas habis, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera isi kertas"
	- Jika tinta kurang, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera isi tinta"
	- Jika energi habis, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera istirahat"
	- Jika pesan terlalu panjang, akan mengeluarkan pesan dari
	  exception, ditambah dengan ", perpendek pesannya"

	Jika memo gagal dibuat, maka tinta, kertas, dan energi tidak
	berkurang. Gunakan metode batalPakaiKertas, batalPakaiTinta,
	dan batalPakaiEnergi.

	Jika berhasil, maka memo akan dimasukkan ke daftar memo serta
	menampilkan pesan "Memo [<nomor_memo>] untuk <untuk> berhasil
	dibuat"

	Keterangan:
	<...> -> ganti dengan nilai yang sesuai.
*/
void Sekretaris::buatMemo(string pesan, string untuk)
{
	// After catch, perlu return kaloga lanjut
	// Digabung juga bisa tapi tetep harus return
	try
	{
		pakaiKertas();
		pakaiTinta(pesan.length());
		pakaiEnergi();
		Memo a(pesan, untuk);
		this->memo[this->memoLength++] = a;
		cout << "Memo [" << this->memoLength << "] untuk " << this->memo[this->memoLength - 1].getUntuk() << " berhasil dibuat" << endl;
	}
	catch (KertasHabisException e)
	{
		cout << e.what() << ", segera isi kertas" << endl;
		return;
	}
	catch (TintaKurangException e)
	{
		cout << e.what() << ", segera isi tinta" << endl;
		batalPakaiKertas();
		return;
	}
	catch (EnergiHabisException e)
	{
		cout << e.what() << ", segera istirahat" << endl;
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		return;
	}
	catch (PesanKepanjanganException e)
	{
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		batalPakaiEnergi();
		cout << e.what() << ", perpendek pesannya" << endl;
		return;
	}
}
/*
	Menggunakan 1 kertas.

	Jika kertas tidak cukup, maka metode ini akan melemparkan
	KertasHabisException dan tidak ada kertas yang digunakan.
*/
void Sekretaris::pakaiKertas()
{
	if (this->kertas <= 0)
	{
		throw KertasHabisException();
	}
	else
	{
		this->kertas--;
	}
}
/*
	Menggunakan tinta sebanyak num.

	Jika tinta tidak cukup, maka metode ini akan melemparkan
	TintaKurangException dan tidak ada tinta yang digunakan.
*/
void Sekretaris::pakaiTinta(int num)
{
	if (this->tinta - num < 0)
	{
		throw TintaKurangException();
	}
	else
	{
		this->tinta -= num;
	}
}
/*
	Menggunakan 1 energi.

	Jika energi tidak cukup, maka metode ini akan melemparkan
	EnergiHabisException dan tidak ada energi yang digunakan.
*/
void Sekretaris::pakaiEnergi()
{
	if (this->energi <= 0)
	{
		throw EnergiHabisException();
	}
	else
	{
		this->energi--;
	}
}
/*
	Membatalkan penggunaan 1 kertas.
*/
void Sekretaris::batalPakaiKertas()
{
	this->kertas += 1;
}
/*
	Membatalkan penggunaan tinta sebanyak num.
*/
void Sekretaris::batalPakaiTinta(int num)
{
	this->tinta += num;
}
/*
	Membatalkan penggunaan 1 energi.
*/
void Sekretaris::batalPakaiEnergi()
{
	this->energi += 1;
}
/*
	Menambahkan jumlah tinta sebanyak num.
*/
void Sekretaris::isiTinta(int num)
{
	this->tinta += num;
}
/*
	Menambahkan jumlah kertas sebanyak num.
*/
void Sekretaris::isiKertas(int num)
{
	this->kertas += num;
}
/*
	Istirahat mengembalikan energi menjadi maksimum.
*/
void Sekretaris::istirahat()
{
	this->energi = ENERGI_MAX;
}
/*
	Menampilkan status dari sekretaris. Berikut adalah format tampilan:
	<...> -> tampilkan nilai yang sesuai
	(...) -> komentar, tidak termasuk output

	--------------
	Status
	  Energi : <jumlah_energi>
	  Tinta : <jumlah_tinta>
	  Kertas : <jumlah_kertas>
	  Memo : <jumlah_memo>
		(untuk setiap memo ke-i, mulai dari 1)
		Memo [<i>]
		  Pesan : <pesan_memo_i>
		  Untuk : <untuk_memo_i>
	--------------

	(Output tidak termasuk ---------- di awal dan akhir)
*/
void Sekretaris::printStatus()
{
	cout << "Status" << endl;
	cout << "  Energi : " << this->energi << endl;
	cout << "  Tinta : " << this->tinta << endl;
	cout << "  Kertas : " << this->kertas << endl;
	cout << "  Memo : " << this->memoLength << endl;
	for (int i = 0; i < memoLength; i++)
	{
		cout << "    Memo [" << i + 1 << "]" << endl;
		cout << "      Pesan : " << this->memo[i].getPesan() << endl;
		cout << "      Untuk : " << this->memo[i].getUntuk() << endl;
	}
}

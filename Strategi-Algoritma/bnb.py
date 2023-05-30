import numpy as np


def branch_and_bound_assignment(cost_matrix):
    n = len(cost_matrix)  # Jumlah pekerjaan dan pekerja

    # Fungsi rekursif untuk mencari solusi optimal
    def backtrack(current_worker, current_assignment, current_cost, used_workers):
        nonlocal best_cost, best_assignment

        # Basis: Semua pekerjaan telah ditugaskan
        if current_worker == n:
            if current_cost < best_cost:
                best_cost = current_cost
                best_assignment = current_assignment.copy()

        else:
            for worker in range(n):
                if worker not in used_workers:
                    # Update biaya sementara dan solusi sementara
                    temp_cost = current_cost + cost_matrix[current_worker][worker]
                    temp_assignment = current_assignment.copy()
                    temp_assignment[current_worker] = worker

                    # Pruning: Cek apakah biaya sementara lebih rendah dari batas atas
                    if temp_cost < best_cost:
                        used_workers.add(worker)
                        backtrack(
                            current_worker + 1, temp_assignment, temp_cost, used_workers
                        )
                        used_workers.remove(worker)

    # Inisialisasi variabel
    best_cost = float("inf")
    best_assignment = []
    used_workers = set()

    # Panggil fungsi rekursif
    backtrack(0, [0] * n, 0, used_workers)

    return best_assignment, best_cost


# Matrix biaya penugasan
cost_matrix = np.array([[9, 2, 7, 8], [6, 4, 3, 7], [5, 8, 1, 8], [7, 6, 9, 4]])


# Panggil algoritma Branch and Bound
assignments, total_cost = branch_and_bound_assignment(cost_matrix)


# Tampilkan hasil
print("Assignment tiap job untuk waktu penyelesaian terpendek:")
for i, assignment in enumerate(assignments):
    job = "Job " + str(i + 1)
    worker = ["Malik", "Bintang", "Matthew", "Zul"][assignment]
    print(job + " --> " + worker)


print("Total waktu penyelesaian terpendek:", total_cost)

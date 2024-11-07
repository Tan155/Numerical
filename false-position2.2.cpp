#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ฟังก์ชัน g(x) ที่เราจะใช้
double func(double x) {
    return 2 + exp(x / 4.0);
}

// วิธี One-Point Iteration
double one_point(double x0, double tol, int maxIter) {
    double x1;
    int iteration = 0;
    do {
        x1 = func(x0);  // คำนวณค่าของ x1
        // คำนวณค่าผิดพลาด
        double error = fabs(x1 - x0);
        // แสดงผลการประมาณค่าและค่าผิดพลาด
        cout << "Iteration " << iteration + 1 << ": x0 = " << x0 << ", x1 = " << x1 << ", Error = " << error << endl;
        if (error < tol) {
            break;  // ออกจากลูปถ้าค่าผิดพลาดน้อยกว่าค่าความแม่นยำ
        }
        x0 = x1;  // อัพเดตค่า x0 สำหรับการวนซ้ำถัดไป
        ++iteration;
    } while (iteration < maxIter);  // ทำการวนซ้ำจนกว่าจะครบจำนวนสูงสุด
    return x1;  // คืนค่าผลลัพธ์สุดท้าย
}

int main() {
    double x0 = 8.0, tolerance = 0.000001;  // ค่าเริ่มต้นและค่าความแม่นยำ
    int maxIter = 10;  // จำนวนสูงสุดของการวนซ้ำ
    double result = one_point(x0, tolerance, maxIter);
    cout << fixed << setprecision(6) << "Final result: " << result << endl;  // แสดงผลลัพธ์สุดท้าย
    return 0;
}

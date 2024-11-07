#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// �ѧ��ѹ g(x) �����Ҩ���
double func(double x) {
    return 2 + exp(x / 4.0);
}

// �Ը� One-Point Iteration
double one_point(double x0, double tol, int maxIter) {
    double x1;
    int iteration = 0;
    do {
        x1 = func(x0);  // �ӹǳ��Ңͧ x1
        // �ӹǳ��ҼԴ��Ҵ
        double error = fabs(x1 - x0);
        // �ʴ��š�û���ҳ�����Ф�ҼԴ��Ҵ
        cout << "Iteration " << iteration + 1 << ": x0 = " << x0 << ", x1 = " << x1 << ", Error = " << error << endl;
        if (error < tol) {
            break;  // �͡�ҡ�ٻ��Ҥ�ҼԴ��Ҵ���¡��Ҥ�Ҥ��������
        }
        x0 = x1;  // �Ѿവ��� x0 ����Ѻ���ǹ��ӶѴ�
        ++iteration;
    } while (iteration < maxIter);  // �ӡ��ǹ��Ө����ҨФú�ӹǹ�٧�ش
    return x1;  // �׹��Ҽ��Ѿ���ش����
}

int main() {
    double x0 = 8.0, tolerance = 0.000001;  // ������������Ф�Ҥ��������
    int maxIter = 10;  // �ӹǹ�٧�ش�ͧ���ǹ���
    double result = one_point(x0, tolerance, maxIter);
    cout << fixed << setprecision(6) << "Final result: " << result << endl;  // �ʴ����Ѿ���ش����
    return 0;
}

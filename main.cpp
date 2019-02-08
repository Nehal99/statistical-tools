#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

string file_name;
ifstream newfile;
ifstream file;
double arr[10000], arr1[10000 / 2], arr2[10000 / 2], data, iqr, q1, q2, q3, x_sum, y_sum, x_sum2, y_sum2, xy_sum, x2, y2, r;
double arr3[10000 / 2], arr4[10000 / 2], arr5[10000 / 2], sum_xy, xmean, ymean, mean1, mean2, se, mse, x_2, a, b, _u;
double sum = 0, sum1 = 0, sum2 = 0, mean = 0 ,stand =0 , RSE=0 ;
int i, j, num, c1, c4, c6, c5, s;

int menu(int num)
{
    cout << "1-Enter a new data set " << endl;
    cout << "2- Load a data set " << endl;
    cout << "3- Display a data set " << endl;
    cout << "4- Calculate the quartiles of the data set " << endl;
    cout << "5-Calculate the Interquartile range " << endl;
    cout << "6-Calculate the Correlation Coefficient of the data set " << endl;
    cout << "7-Calculate the median value of the data set " << endl;
    cout << "8-Calculate linear regression coefficients " << endl;
    cout << "9-Calculate the mean square error MSE of the linear regression of 8" << endl;
    cout << "10-Calculate the mean and standard deviation of the data set" << endl;
    cout << "11-Relative standard deviation" << endl;
    cout << "12-Calculate the mode value of the data set" << endl;
    cout << "13- End" << endl;

    cout << "Enter number of Operation you want to do: ";
    cin >> num ;
    return num ;
}
void EnterData(string file_name)
{
	ofstream file;

	cout << "Enter number of data: " ;
    cin >> s ;

	file.open(file_name.c_str());

	if (file.is_open())
	{
		cout << "Enter new data sets: " << endl ;
		for (int r=0 ; r<s ; r++ )
        {
            cin >> data;
            file << data << " " ;
        }
	}
	else { cout << "Error while opening the file"; }
	file.close() ;
}
void LoadData(string file_name)
{
    i=0 ;
    j=0 ;
	ifstream file;
	file.open(file_name.c_str());

	if (file.is_open())
	{
		double data;
		while (file >> data) { i++; }
		arr[i];
		file.close();

		newfile.open(file_name.c_str());
		while (newfile >> arr[j]) { j++; }
	}
	else { cout << "Error while opening the file"; }
}
void ReadData(string file_name)
{
	LoadData(file_name);
	for (int j = 0; j<i; j++) { cout << arr[j] << " "; }
	cout << endl;
}
void quar(double arr[10000], double &q1, double &q2, double &q3, int i)
{
    int c4=0 , c6 = 0 , temp2=0 , temp3=0 , temp4=0 , c1=0 ;
    double Q1= 0 , Q2= 0 ,Q3= 0 ;
    q1=0 ;
    q2=0 ;
    q3=0 ;
	for (int a = 0; a < i; a++)
	{

		for (int b = 0; b<i - 1; b++)
		{
			if (arr[b]>arr[b + 1])
			{
				double temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
			}
		}

	}
	for (int p = 0; p < i; p++)
	{
		cout << arr[p] << " ";
	}
	cout << endl;
	if (i % 2 == 0)
	{
		for (int c3 = 0; c3 < (i / 2); c3++) {c4++;}

		if (c4 % 2 == 0)
		{
            Q1 = (arr[(c4 / 2) - 1] + arr[((c4 / 2) + 1) - 1]) / 2;
			q1 = Q1;
		}
		else
		{
			int Q1 = (c4 + 1) / 2;
			q1 = arr[(Q1 - 1)];
		}

		Q2 = (arr[(i / 2) - 1] + arr[((i / 2) + 1) - 1]) / 2;
		q2 = Q2;

		for (int c5 = 0; c5 < (i / 2); c5++) {c6++;}

		if (c6 % 2 == 0)
		{
            Q3 = (arr[(c6 / 2) + (i / 2) - 1] + arr[((c6 / 2) + 1) + (i / 2) - 1]) / 2;
			q3 = Q3;
		}
		else
		{
			int Q3 = (((c6 + 1) / 2) + (i / 2));
			q3 = arr[(Q3 - 1)];
		}
	}
	//Calc. of Q1 Q2 Q3 when the number is odd
	else
	{
		temp2 = ((i + 1) / 2);
		q2 = arr[temp2 - 1];
		if (temp2 % 2 == 0)
		{
			temp3 = temp2 - 1;
			int Q1 = ((temp3 + 1) / 2);
			q1 = arr[Q1 - 1];
		}
		else
		{
			temp4 = temp2 - 1;
			Q1 = (arr[(temp4 / 2) - 1] + arr[(((temp4 / 2) + 1) - 1)]) / 2;
			q1 = Q1;

		}
		for (int c2 = temp2; c2 < i; c2++) {c1++;}

		if (c1 % 2 == 0)
		{
			Q3 = (arr[(c1 / 2) - 1 + temp2] + arr[((c1 / 2) + 1) - 1 + temp2]) / 2;
			q3 = Q3;
		}
		else
		{
            int Q3 = (c1 + 1) / 2;
			q3 = arr[(Q3 - 1) + temp2];

		}
	}


}
double median( double arr[10000], double &q2, int i)
{
	if (i%2==0)
	{
		double Q2 = (arr[(i / 2) - 1] + arr[((i / 2) + 1) - 1]) / 2;
		q2 = Q2;
	}
	else
	{
		int temp2 = ((i + 1) / 2);
		q2 = arr[temp2 - 1];
	}
	return q2;
}
void IQR(double arr[10000], double &iqr, int i, double &q1, double &q3)
{
	iqr = q3 - q1;
}
double cr_cf(double arr[], double &r, int i)
{
    for (int f = 0; f< i / 2; ++f)
    {
        arr1[f] = arr[f] ;
        arr2[f] = arr[f + (i / 2)];
    }
    for (int a = 0; a < i / 2; a++) {xy_sum += arr1[a] * arr2[a];}
    for (int e = 0; e <i / 2; e++)
    {
        x_sum += arr1[e];
        x2 += pow(arr1[e], 2);
    }
    for (int e = 0; e < i / 2; e++)
    {
        y_sum += arr2[e];
        y2 += pow(arr2[e], 2);
    }

    x_sum2 += pow(x_sum, 2);
    y_sum2 += pow(y_sum, 2);

    r = (((i / 2)*(xy_sum)) - ((x_sum)*(y_sum))) / sqrt((((i / 2)*(x2)) -( x_sum2))*(((i / 2)*(y2)) - (y_sum2)));
    return r;
}
void linear (double arr[10000] , double &a , double &b)
{
    for (int r = 0; r< i / 2; ++r)
    {
        arr3[r] = arr[r];
        arr4[r] = arr[r + (i / 2)];
    }
    sum_xy = 0;
    for (int r=0 ; r<i/2 ; r++) {sum_xy += arr3[r]*arr4[r] ;}
    mean1 = 0;
    mean2 = 0;
    xmean = 0;
    ymean = 0;
    x_2 = 0;
    for (int r=0 ; r<(i/2) ; r++ )
    {
        mean1+=arr3[r] ;
        x_2+=pow(arr3[r],2) ;
    }
    xmean=mean1/(i/2) ;
    for (int r=0 ; r<(i/2) ; r++ ){mean2+=arr4[r];}

    ymean=mean2/(i/2) ;
    b=(sum_xy-((i/2)*xmean*ymean))/(x_2-((i/2)*(pow(xmean,2))));
    a=ymean-(b*xmean) ;
}
double MSE(double arr[10000] , double &mse , int i)
{
	a = 0;
	b = 0;
	linear(arr , a , b) ;
	cout << "new values of y: " ;
	for (int r=0 ; r<(i/2) ; r++)
	{
		_u=(b*arr3[r])+ a ;
		arr5[r]=_u ;
		cout << arr5[r] << endl ;
	}
	cout << "Error: " ;
	for(int r=0 ; r<(i/2) ; r++) {cout << arr4[r]-arr5[r] << endl ;}
	cout << "Error power 2: " ;
	for(int r=0 ; r<(i/2) ; r++)
	{
	cout << pow((arr4[r]-arr5[r]),2)<< endl;
	se += pow((arr4[r]-arr5[r]),2) ;
	}
	mse=se/(i/2) ;
	return mse ;
}
void st_dv(double arr[10000] , double &mean , double &stand , int i )
{
	mean = 0;
	stand = 0;
	sum = 0;
	sum1 = 0;
	sum2 = 0;
	for (int c5 = 0; c5 <= i; c5++) { sum += arr[c5]; }
	mean = sum / i;
	for (int m = 0; m < i; m++) {sum1 += pow((arr[m] - mean), 2);}
    sum2 = sum1 / (i - 1);
    stand = sqrt(sum2) ;

}
double rse(double arr[10000], double &mean , double &stand , int i)
{

	st_dv ( arr , mean , stand, i ) ;
	RSE = (stand / mean) * 100;
	return RSE ;
}
double getMax(double rep[], int i)
{
	double maxx = rep[1];
	for (int u = 3; u < i; u += 2)
	{
		if (rep[u] > maxx) { maxx = rep[u]; }
	}
	return maxx;
}
bool check_for_mode(double rep[], int i)
{
	double maxx = getMax(rep, i);
	int counter = 0;
	if (i == 2) { return false; }
	for (int u = 1; u < i; u += 2)
	{
		if (rep[u] == maxx) { counter++; }
	}
	if (counter > 1) { return false; }
	return true;
}
double get_mode(double rep[], int i)
{
	double maxx = rep[1]; int pos = 1;
	for (int u = 3; u<i; u += 2)
	{
		if (rep[u] > maxx) { maxx = rep[u]; pos = u; }
	}
	return rep[--pos];
}
bool check_for_repetation(double rep[], int i, double item)
{
	for (int u = 0; u<i; u += 2)
	{
		if (rep[u] == item) { return true; }
	}
	return false;
}
int main()
{
    string file_name;
	while (num != 13)
	{
	    num = menu(num);
		if (num == 1)
		{
		    cin.ignore() ;
			cout << "Enter file name: " ;
			getline(cin, file_name) ;
            EnterData(file_name) ;
		}
		if (num == 2)
		{
		    cin.ignore() ;
			cout << "Enter file name: ";
			getline(cin, file_name);
			LoadData(file_name);
			cout << endl;
		}
		if (num == 3)
		{
		    cin.ignore() ;
			cout << "Enter file name: ";
			getline(cin, file_name);
			ReadData(file_name);
		}
		if (num == 4)
		{
		    cin.ignore() ;
			quar(arr, q1, q2, q3, i);
			cout << endl;
			cout << "Q1 = " << q1 << endl;
			cout << "Q2 = " << q2 << endl;
			cout << "Q3 = " << q3 << endl;

		}
		if (num == 5)
		{
		    cin.ignore() ;
			q1 = 0;
			q2 = 0;
			q3 = 0;
			quar(arr, q1, q2, q3, i);
			IQR(arr, iqr, i, q1, q3);
			cout << "IQR= " << iqr;
			cout << endl;
		}
		if (num == 6)
		{
		    cin.ignore() ;
		    if (i%2!=0) {cout << "Please enter an even data " << endl;}
		    else
            {
                cr_cf(arr , r, i);
                cout << "Correlation Coefficient of the data set= " << r;
                cout << endl;
            }
		}
		if (num== 7)
		{
		    cin.ignore() ;
			median(arr, q2, i);
		    cout << "Median is " <<q2 ;
			cout << endl;
		}
		if (num== 8)
		{
		    cin.ignore() ;
		    if (i%2!=0) {cout << "Please enter an even data " << endl ;}
		    else
            {
                linear(arr , b , a) ;
                cout << "y= " << a << "x + " << b  ; ;
                cout << endl ;
            }
		}
		if (num== 9)
		{
		    cin.ignore() ;
		    if (i%2!=0) {cout << "Please enter an even data " << endl ;}
		    else
            {
                MSE(arr , mse , i) ;
                cout << "MSE= " << mse ;
                cout << endl ;
            }
        }
		if (num == 10)
		{
		    cin.ignore() ;
			st_dv(arr, mean, stand, i);
			cout << "MEAN = " << mean << endl ;
			cout << "STANDARD DEVIATION = " << stand << endl;
			cout << endl;
		}
		if (num == 11)
		{
		    cin.ignore() ;
			rse(arr,mean , stand , i) ;
			cout << "RSE= " << RSE << "%";
			cout << endl;
		}
		if (num == 12)
		{
		    cin.ignore() ;
			int counter = 0, index = 0;
			int size2 = i * 2;
			double rep[10000] = {};
			double item = 0.0;
			for (int v = 0; v < i; ++v)
			{
				item = arr[v];
				counter = 0;
				if (check_for_repetation(rep, i, item) == true) { continue; }
				for (int _v = 0; _v< i; ++_v)
				{
					if (arr[_v] == item) { counter++; }

				}
				rep[index] = item;
				rep[index + 1] = counter;
				index += 2;

			}
			if (check_for_mode(rep, 2 * i) == true)
			{
				cout << "MODE is :" << get_mode(rep, i) << endl;
			}
			else
			{
				cout << " NO MODE IN THIS DATA \n";
			}
		}
	}
}


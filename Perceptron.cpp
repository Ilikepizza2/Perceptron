#include <bits/stdc++.h>
using namespace std;

vector<double> split_nums(string& line){
    vector<double> vs;
    string temp="";
    for(int i=0;i<line.length();i++){
        if(line[i]!=',')
            temp.push_back(line[i]);
        else{
            vs.push_back(stod(temp));
            temp="";
        }
    }
    vs.push_back(stoi(temp)); // the last value
    return vs;
}

void printCols(vector<vector<double>> inputs, vector<int> outputs){
    int ind=0;
    for(auto i: inputs){
        for(auto j: i){
            cout<<j<<',';
        }
        cout<<outputs[ind]<<'\n';
        ind++;
    }
}

void initializeRandomWeights(vector<double>& weights_and_bias) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1.0, 1.0);  // Adjust the range based on your problem

    for (double& weight : weights_and_bias) {
        weight = dis(gen);
    }
}

double sum(vector<double> v1, vector<double> v2){
    v2.push_back(1); // bias term
    double sum=0;
    for(int i=0;i<v1.size();i++){
        sum += v1[i]*v2[i];
    }
    return sum;
}

int classifier(vector<double> weights_and_bias, vector<double> input){
    if(sum(weights_and_bias, input)>0)
        return 1;
    return 0;
}

int main(){
    fstream fin, fout;
    fin.open("placement.csv", ios::in);
    vector<vector<double>> inputs;
    vector<int> outputs;
    string temp;
    fin>>temp; // eating up the first column(heading)
    while(fin >> temp){
        vector<double> splitted_nums = split_nums(temp);
        inputs.push_back({});
        for(int i=0;i<splitted_nums.size()-1;i++){
            inputs.back().push_back(splitted_nums[i]);
        }
        outputs.push_back(splitted_nums.back());
    }
    // printCols(inputs, outputs);


    vector<double> weights_and_bias(inputs.size()+1, 1);
    initializeRandomWeights(weights_and_bias);
    double learning_rate = 0.1;
    int epochs = 1e3;

    // training
    while(epochs--){
        int random_index = rand()%inputs.size();
        for(int i=0;i<inputs[random_index].size();i++){
            // perceptron trick
            weights_and_bias[i] += learning_rate*(outputs[random_index] - classifier(weights_and_bias, inputs[random_index]))*inputs[random_index][i];
        }
    }



    // testing
    fin.close();
    fin.open("test.csv", ios::in);
    fin>>temp; // eating up the first column(heading)
    while(fin >> temp){
        vector<double> splitted_nums = split_nums(temp);
        cout<<classifier(weights_and_bias, splitted_nums)<<'\n';
    }

    return 0;
}
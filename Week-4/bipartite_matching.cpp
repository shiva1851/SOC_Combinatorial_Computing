#include<bits/stdc++.h>
using namespace std;
// matching function to find if a valid assignment possible
bool matching(const vector<vector<int>> &pref, vector<int> &job){
//each row of pref shows each worker
//first element of each row is no of preferences followed by preferred jobs
//hence pref is of order nx(m+1)
    int n=pref.size();//no of workers
    int m=pref[0].size()-1;//no. of jobs
    vector <int> assigned_job(n,-1); //stores job assigned to each worker, initialize to -1 
    vector <int> count_job(m,0); //stores no of workers assigned to each job
    //create adjacency list connecting workers to preferred job
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){//loop over all workers
        for(int j=1; j<=pref[i][0]; j++){//loop over all preferences of ith worker
            adj[i].push_back(pref[i][j]);
        }
    }

    //use bfs for matching
    //we iterate over the preferences of worker in a queue, and if the job is available then we assign it.
    queue<int> q;
    for(int i=0; i<n; i++){//loop over workers
        for(int j=0; j<adj[i].size(); j++){//loop over preferences of each worker
            int x=adj[i][j];//denotes the job
            //checks whether worker is free for job and job not assigned to anyone else
            if (assigned_job[i]==-1 && count_job[x-1]==0){
                assigned_job[i]=x;//update the worker job status
                count_job[x-1]=1;//update the job occupied status, max one can occupy a job
            }
        }

        if(assigned_job[i]==-1){// if ith worker has not found job
            q.push(i); // add him to the que of unemployed workers
        }
    }

    //now we continue the loop till the queue is empty. we take the 1st element of queue as the worker, process it and then dequeue it.
    while(!q.empty()){
        int worker=q.front();
        q.pop();
        for(int j=0; j<=adj[worker].size(); j++){
            int jobs=adj[worker][j];
            if (count_job[jobs-1]==0){//the job is available
                int assignedWorker=assigned_job[worker];
                assigned_job[worker]=jobs;
                count_job[jobs-1]=1;
                if (assignedWorker !=-1){
                    q.push(assignedWorker);
                }
                break;
            }
// if a job is assigned to another worker, unassign it and push it to unemployed worker queue and assign that job to actual worker
            else if (assigned_job[worker]!=jobs && count_job[jobs-1]>0){
                int assignedWorker=job[jobs-1];
                q.push(assignedWorker);
                assigned_job[assignedWorker]=-1;//unassign the work from the worker
                assigned_job[worker]=jobs;
                count_job[jobs-1]=1;
                break;
            }
    }
}

//we check if all workers assigned work
for(int i=0; i<n; i++){
    if (assigned_job[i]==-1){
        return false;
    }
}

// now for final printing of output we wiil transfer the data stored in assigned_job to our global vector job
//because assigned_job is limited to scope of function and cannot be used in main
//first we resize job vector to required size n
job.resize(n);
//now to transfer data
for(int i=0; i<n; i++){
    job[i]=assigned_job[i];
}

return true;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> pref(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        pref[i].push_back(k);
        for (int j = 0; j < k; j++) {
            int jobs;
            cin >> jobs;
            pref[i].push_back(jobs);
        }
    }


    vector<int> job;
    if (matching(pref, job)) {
        for (int i = 0; i < n; i++) {
            cout << i+ 1 << " " << job[i] << endl;
        }
    } else {
        cout << "-1" <<endl;
}
}
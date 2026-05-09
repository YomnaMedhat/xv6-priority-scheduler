
int main(){

int pid = fork();

if(pid ==  0){
print("CHILD");
execlp("ls" , "ls" , "null");
exit(0);
}
else{
wait(10);
}
}

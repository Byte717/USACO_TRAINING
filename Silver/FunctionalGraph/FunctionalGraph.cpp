

bool visited[MAXN], on_stack[MAXN];
int number_of_cycles = 0, next_node[MAXN];

void dfs(int n) {
	visited[n] = on_stack[n] = true;
	int u = next_node[n];
	if (on_stack[u]) number_of_cycles++;
	else if (!visited[u]) dfs(u);
	on_stack[n] = false;
}


void succ(int x){
    return;
}

int calculateFirstNodeInLoop(int x){
    a = succ(x);
    b = succ(succ(x));
    while (a != b) {
        a = succ(a);
        b = succ(succ(b));
    }
    a = x;
    while (a != b) {
        a = succ(a);
        b = succ(b);
    }
    first = a;
}

int cycleLength(){
    int a = calculateFirstNodeInLoop(a);
    b = succ(a);
    length = 1;
    while (a != b) {
        b = succ(b);
        length++;
    }
}
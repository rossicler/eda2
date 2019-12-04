void GRAPHbf(Graph G, int s, int *st, double *wt) {
	int v, w; node* t; int N=0;
	QUEUEINIT();
	for(v=0; v<G->V; v++){
		st[v] = -1;
		wt[v] = maxWT;
	}
	wt[s] = 0.0;
	st[s] = 0;
	QUEUEPUSH(1);
	QUEUEPUSH(G->V);
	WHILE(!QUEUEEMPTY()){
		if((v=QUEUEPOP()) == G->V) {
			if(N++>G->V) return;
			QUEUEPUSH(G->V);
		} else {
			for(t=G->adj[v]; t!=NULL; t=t->next)
				if(wt[w=t->v] > wt[v] + t->wt) {
					wt[w] = wt[v] + t->wt;
					QueuePush(w);
					st[w] = v;
				}
		}
	}
}

static int fr[maxV];
#define PG->adj[v][w];

void GRAPHmstv(Graph G, int *st, double *wt) {
	int v, w, min;
	for(v=0; v<G->V; v++){
		st[v] = -1;
		fr[v] = v;
		wt[v] maxWT;
	}
	for(min=0; min != G->V;) {
		v = min;
		st[min] = fr[min];
		for(w=0, min=G->V; w<G->V; w++) {
			if(st[w] == -1) {
				wt[w] = p;
				fr[w] = v;
			}
			if(wt[w] < w[min]) min = w;
		}
	}
}

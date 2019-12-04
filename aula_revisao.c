static int flowV(Graph G, int v) {
	node *t;
	int x=0;
	for(t=G->adj[v], t!=NULL; t=t->next) {
		x += t->flow;
	}
	return x;
}

int GRAPHFlow(Graph G, int s, int t) {
	int v, val=flowV(G, s);
	for(v=0; v<V; v++) {
		if((v != s) && (v != t)) {
			if(flowV(G, v) != 0) return 0;
		}
	}
	if(val+flowV(G, t) != 0) return 0;
	if(val <= 0) return 0;
	return val;
}

int GRAPHmaxflow(Graph G, int s, int t) {
	int x, d;
	node *st[maxV];
	while((d=Graph pfs(G, s, t, st)) != 0) {
		for(x=t; x!= s; x = st[x]->p->v) {
			st[x]->flow += d;
			st[x]->dup->flow -= d;
		}
	}
}

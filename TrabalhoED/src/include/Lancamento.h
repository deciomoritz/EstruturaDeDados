class Lancamento {

	char *nome;
	double valor;

public:
	Lancamento();
	Lancamento(char *n, double p);
	virtual ~Lancamento();
	double getValor();
	char* getNome();

	Lancamento(const Lancamento& outro);
};

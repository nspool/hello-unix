
/* PLEXER */

#include <stdio.h>
#include <stdlib.h>

#define BSIZE 255

char buf[BSIZE] = {0};
FILE* fout;


int enplex(FILE* fin)
{
	int err, i;

	err = fread(buf, 1, BSIZE, fin);

	if(err < BSIZE)
	{
		if(err == EOF) err = BSIZE;
		for(i=err; i<BSIZE; i++)
			buf[i] = 0;

		fwrite(buf, BSIZE, 1, stdout);
		fputc(err, stdout);
		fputc('a', stdout);
		return 1;
	}
	else
	{
		fwrite(buf, BSIZE, 1, stdout);
		fputc('\0', stdout);
		fputc('\0', stdout);
	}

	return 0;
}


int deplex(FILE* fout)
{
	int err, i, mark1, mark2;
	err = fread(buf, 1, BSIZE, stdin);
	
	if( (mark1 = fgetc(stdin)) == EOF){ fclose(fout); return 1; }
	if( (mark2 = fgetc(stdin)) == EOF){ fclose(fout); return 1; }
	if( mark1 == 0 && mark2 == 'a'){ fclose(fout); return 1; }
 
	if(mark1 > 0)
	{
		for(i=0; i<mark1; i++)
			fputc(buf[i], fout);

		fclose(fout);
		return 1;
	}

	fwrite(buf, BSIZE, 1, fout);

	return 0;
}


int main(int argc, char* argv[])
{

	FILE *fin[10];
	FILE* fout[10];

	int err;
	int remaining, total;
	char c;
	char fname[256];
	int f,t,i;


	t = f = i = 0;
	remaining = 0;

	if(argc > 1) /* Read plexed input from stdin */
	{
		// File header
		for(i=1; i<argc; i++)
		{
		
			fin[i] = fopen(argv[i], "rb");
		
			if(fin[i]) {
				printf("|%s",argv[i]);		
				remaining++;
			}
		}
		printf("||");

		// Read block chunks

		i=1;

		while(remaining > 0)
		{
			if(!feof(fin[i]))
			{
				enplex(fin[i]);

				if(feof(fin[i]))
					remaining--;
			}

			i++;
			i = i % argc;
			if(i == 0) i=1;
		}


	}
	else /* read file names from argv and create plexed output on stdout */
	{
		while(c = getc(stdin))
		{
			if(c == '|')
			{
				t++;
				remaining++;
			
				if(t>1 && f==0)
				{
					remaining -= 2;
					break;
				}
			
				if(f>0)
				{
					fout[i] = fopen(fname, "wb");
					i++;
					f=0; t--;
				}
			}
			else
			{
				fname[f] = c;
				f++;
				fname[f] = '\0';
			}
		}

		total = i;

		i=0;

		while(remaining > 0)
		{
			// printf("%d\n", i);
			if(fout[i] != 0)
			{
				if(deplex(fout[i]) == 1)
				{
					fout[i] = 0;
					remaining--;
				}
			}
			i++;
			i=i%total;
		}

	}

	return 0;
}


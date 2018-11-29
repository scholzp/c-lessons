#include <stdio.h>
#include <unistd.h>

struct Pixel{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

int main (int argc, char ** argv)
{
  char * fname;
  FILE *fp;
  if (argc == 2){
    fname = argv[1];
  }
  if( access( fname, F_OK ) != -1 ) {
    printf("%s does exist!\n", fname);
    fp = fopen(fname, "r");
    unsigned char linebuffer[255];
    int linecount = 0;
    //read header
    printf("Reading file...\n");
    /*
    if(fgets(linebuffer, 3, (FILE*) fp) != NULL)
      printf("File format is: %2s\n", linebuffer );
    else
      printf("Read wasnt succesfull\n");
      */
    int pos = -1;
    do{
      ++pos;
      linebuffer[pos] = fgetc((FILE*) fp);
    }while (linebuffer[pos] != 10 && pos < 255);
    printf("Dimension: %s \n", linebuffer );
    fclose(fp);
  } else {
    printf("%s doesn't exist\n", fname );
    // file doesn't exist
  }
  return 0;

}

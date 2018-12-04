#include <stdio.h>
#include <unistd.h>


#define BUFFERSIZE  1024

struct matrix{
  unsigned int height;
  unsigned int width;
  int * data;
};

struct bufferElem{
  int buffer[BUFFERSIZE];
  struct bufferElem *next;
};

struct bufferList{
  struct bufferElem element;
  struct bufferElem *next;
};

int multiplication(int heightA, int widthA, int heightB, int widthB, int A[heightA][widthA], int B[heightB][widthB]){
  if (widthA =! heightB) {
    printf("The width of Matrix A should be equal to the height of Matrix B\n");
    return 0;
  }
  for (int i = 0; i > widthA; ++i){
    //multiplication
  }
}



int main(int argc, char ** argv) {

  FILE *fp;
  char * fname;

  if (argc == 2){
    fname = argv[1];


    if( access( fname, F_OK ) != -1 ) {
      int height, width;
      height = width = 0;
      printf("%s does exist!\n", fname);
      fp = fopen(fname, "r");
      int linebuffer[BUFFERSIZE];
      for(int i = 0; i < BUFFERSIZE; ++i)
        linebuffer[i] = 0;
      //read header
      printf("Reading file...\n");
      /*
      if(fgets(linebuffer, 3, (FILE*) fp) != NULL)
      printf("File format is: %2s\n", linebuffer );
      else
      printf("Read wasnt succesfull\n");
      */
      int pos = -1;
      int widthCount = 0;
      long unsigned totalByte = 0;
      //start reading file
      do{
        //inc buffer pos
        ++pos;
        // read exactly one byte
        linebuffer[pos] = fgetc(fp);
        //check if read byte is ','
        if(linebuffer[pos] == 44)
          //..if so inc widthcount
          ++widthCount;
        //check if read byte is NL
        if(linebuffer[pos] == 10){
          //if so, in height and...
          ++height;
          //check if this had more elements than line before
          if(width < widthCount + 1)
            width = widthCount + 1;
          //new line mean, that we start at 0 for counting elements
          widthCount = 0;
        }
        //ensure that there is no bufferoverflow
        if(pos == BUFFERSIZE-1){
          totalByte += pos;
          pos = 0;
        }
      }while (linebuffer[pos] != EOF);
      totalByte += pos;
      printf("Buffer:\n" );
      fclose(fp);
      for(int i = 0; i < BUFFERSIZE; ++i)
        printf("%d ", (char) linebuffer[i]);
      printf("\nColumns: %d\n", height);
      printf("Width: %d \n", width);
      printf("Total Bytes read: %ld\n", totalByte);
    } else {
      printf("%s doesn't exist\n", fname );
      // file doesn't exist
    }
  }



  return 0;
}

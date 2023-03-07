
# location where outputs from terminal is located
Terminal_Output=./outputs/actual

# location where expected output files are located
EXPECTED_OUTPUTS=./outputs/Expected

#Iterate over all actual output files
for actual_file in $Terminal_Output/*
do
  filename=$(basename "$actual_file")

  # we have kept the file names of actual output and expected output to be the same.
  # if output of the both the files are same, bash echos PASSED or esle echos FAILED
  echo "comparing $Terminal_Output/$filename with $EXPECTED_OUTPUTS/$filename"
  
  if diff $Terminal_Output/$filename $EXPECTED_OUTPUTS/$filename; then
    echo "PASSED"
  else
    echo "Failed"
  fi
done
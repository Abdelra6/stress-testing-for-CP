set -e
g++ soln.cpp -o soln
g++ test.cpp -o test
g++ brute.cpp -o brute
for((i = 1;i<=1000000 ; ++i)); do
    ./test $i > input_file
    ./soln < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || exit
    echo "Passed test: "  $i
done
echo "all pretests passed"
#cat input_file
#echo "Your answer is:"
#cat myAnswer
#echo "Correct answer is:"
#cat correctAnswer
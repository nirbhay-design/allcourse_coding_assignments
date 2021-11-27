// int slices=0;
// Semaphore orderPizza, deliver;
// Lock mutex;
// bool first = true, havePizza = false;
// Students() {
// while(TRUE) {
// mutex.Acquire();
// while( !havePizza ) {
// if( slices > 0 ) {
// slices--;
// havePizza = true;
// }
// else {
// if( first ) {
// orderPizza.Signal(mutex);
// first = false;
// }
// deliver.Wait(mutex);
// }
// } // end while !havePizza
// mutex.Release();
// Study();
// havePizza = false;
// }
// }
// Pizza Hut() {
// while(TRUE) {
// mutex.Acquire();
// orderPizza.Wait(mutex);
// makePizza();
// slices = S;
// first=true;
// deliver.Signal(mutex);
// mutex.Release();
// }
// }


int slices=0;
Semaphore orderPizza, deliver;
Lock mutex;
bool first = true, havePizza = false;
Students() {
while(TRUE) {
mutex.Acquire();
while( !havePizza ) {
if( slices > 0 ) {
slices--;
havePizza = true;
}
else {
if( first ) {
orderPizza.Signal(mutex);
first = false;
}
deliver.Wait(mutex);
}
} // end while !havePizza
mutex.Release();
Study();
havePizza = false;
}
}
Pizza Hut() {
while(TRUE) {
mutex.Acquire();
orderPizza.Wait(mutex);
makePizza();
slices = S;
first=true;
deliver.Signal(mutex);
mutex.Release();
}
}
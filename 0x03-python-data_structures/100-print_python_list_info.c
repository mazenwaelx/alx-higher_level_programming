#include <stdio.h>
#include <Python.h>

void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item, *repr;

    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);

    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        repr = PyObject_Repr(item);
        printf("Element %ld: %s\n", i, PyUnicode_AsUTF8(repr));
        Py_DECREF(repr);
    }
}

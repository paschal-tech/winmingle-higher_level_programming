#include <Python.h>
#include <stdio.h>

/**
 *  * print_python_list - Prints basic information about a Python list
 *   * @p: Python list
 *    */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyListObject *list;
	PyObject *item;

	printf("[*] Python list info\n");
	size = ((PyVarObject *)p)->ob_size;
	list = (PyListObject *)p;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		item = list->ob_item[i];
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
	}
}

/**
 *  * print_python_bytes - Prints basic information about a Python bytes object
 *   * @p: Python bytes object
 *    */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i, limit;
	char *str;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)p)->ob_size;
	str = ((PyBytesObject *)p)->ob_sval;


	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	limit = size + 1;
	if (limit > 10)
		limit = 10;


	printf("  first %ld bytes:", limit);

	for (i = 0; i < limit; i++)
		printf(" %02x", (unsigned char)str[i]);


	printf("\n");
}

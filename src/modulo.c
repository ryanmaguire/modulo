/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  This file is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this file.  If not, see <https://www.gnu.org/licenses/>.       *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Simple example of using the C-Python API for extension modules.       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  All of the Python API tools and typedef's are found here.                 */
#include <Python.h>

/*  Modulo function prototypes are given here.                                */
#include "modulo.h"

/*  Helper macro for creating a Python wrapper to all of the C functions.     */
#define CREATE_PYTHON_FUNCTION(cname)                                          \
static PyObject * py##cname(PyObject *self, PyObject *args)                    \
{                                                                              \
    unsigned int n;                                                            \
                                                                               \
    if (!PyArg_ParseTuple(args, "I", &n))                                      \
        return NULL;                                                           \
                                                                               \
    return Py_BuildValue("I", cname(n));                                       \
}

/*  Create Python wrappers for all of the functions.                          */
CREATE_PYTHON_FUNCTION(mod4)
CREATE_PYTHON_FUNCTION(mod4_bit)
CREATE_PYTHON_FUNCTION(mod4_shift)
CREATE_PYTHON_FUNCTION(mod4_slow)
CREATE_PYTHON_FUNCTION(mod25)
CREATE_PYTHON_FUNCTION(mod25_slow)

/*  We're done with the helper macro now, so we can undefine it.              */
#undef CREATE_PYTHON_FUNCTION

/*  All functions available in the Python module.                             */
static PyMethodDef ModuloMethods[] = {
    {
        "mod4",
        pymod4,
        METH_VARARGS,
        "Computes mod 4 of an integer using tricks in Hacker's Delight."
    },
    {
        "mod4_bit",
        pymod4_bit,
        METH_VARARGS,
        "Computes mod 4 of an integer using the bit-wise-and method."
    },
    {
        "mod4_shift",
        pymod4_shift,
        METH_VARARGS,
        "Computes mod 4 of an integer using the bit-shifting trick."
    },
    {
        "mod4_slow",
        pymod4_slow,
        METH_VARARGS,
        "Computes mod 4 of an integer using the by-hand method."
    },
    {
        "mod25",
        pymod25,
        METH_VARARGS,
        "Computes mod 25 of an integer using tricks in Hacker's Delight."
    },
    {
        "mod25_slow",
        pymod25_slow,
        METH_VARARGS,
        "Computes mod 25 of an integer using the by-hand method."
    },

    /*  End of array element. All entries have their zero values.             */
    {NULL, NULL, 0, NULL}
};

/*  The struct representing the Python module. You can import it at the       *
 *  python level via "import modulo".                                         */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "modulo",
    NULL,
    -1,
    ModuloMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

/*  And lastly, the function that creates the Python module.                  */
PyMODINIT_FUNC
PyInit_modulo(void)
{
    return PyModule_Create(&moduledef);
}

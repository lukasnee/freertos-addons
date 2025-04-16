/****************************************************************************
 *
 *  Copyright (c) 2025, Michael Becker (michael.f.becker@gmail.com)
 *  Original work by: Lukas Neverauskis (lukas.neverauskis@gmail.com)
 *
 *  This file is part of the FreeRTOS Add-ons project.
 *
 *  Source Code:
 *  https://github.com/michaelbecker/freertos-addons
 *
 *  Project Page:
 *  http://michaelbecker.github.io/freertos-addons/
 *
 *  On-line Documentation:
 *  http://michaelbecker.github.io/freertos-addons/docs/html/index.html
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files
 *  (the "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so,subject to the
 *  following conditions:
 *
 *  + The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *  + Credit is appreciated, but not required, if you find this project
 *    useful enough to include in your application, product, device, etc.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 *  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************/

#ifndef TIMEOUT_HPP_
#define TIMEOUT_HPP_

#include "FreeRTOS.h"
#include "task.h"

namespace cpp_freertos {

/**
 *  Class encapsulating FreeRTOS timeout functionality (TimeOut_t). Timeout
 *  keeps track of the time elapsed since its creation. It simplifies total
 *  timeout handling for a sequence of multiple blocking operations.
 */
class Timeout {

public:
    /**
     *  Constructor.
     *
     *  @param TimeoutTicks Number of ticks to wait before timing out.
     */
    Timeout(TickType_t Ticks);

    /**
     *  Destructor.
     */
    virtual ~Timeout();

    /**
     *  Ticks left until timeout.
     *
     *  @return Number of ticks left until timeout.
     */
    TickType_t Left();

    /**
     *  Check if the timeout has expired.
     *
     *  @return true if the timeout has expired, false otherwise.
     */
    bool Expired();

private:
    /**
     *  Number of ticks left until timeout.
     */
    TickType_t TicksLeft = 0;

    /**
     * The underlying FreeRTOS timeout structure.
     */
    TimeOut_t xTimeOut;
};

}
#endif

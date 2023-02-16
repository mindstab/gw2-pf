/*
MIT License

Copyright (c) 2023 mindstab <zeropolyz@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "pf/formats/mapc/area.hpp"
#include "pf/formats/mapc/audi.hpp"
#include "pf/formats/mapc/bloc.hpp"
#include "pf/formats/mapc/cg15.hpp"
#include "pf/formats/mapc/cube.hpp"
#include "pf/formats/mapc/dcal.hpp"
#include "pf/formats/mapc/edit.hpp"
#include "pf/formats/mapc/env.hpp"
#include "pf/formats/mapc/exp.hpp"
#include "pf/formats/mapc/havk.hpp"
#include "pf/formats/mapc/laye.hpp"
#include "pf/formats/mapc/lght.hpp"
#include "pf/formats/mapc/msn.hpp"
#include "pf/formats/mapc/nm15.hpp"
#include "pf/formats/mapc/nmex.hpp"
#include "pf/formats/mapc/obs.hpp"
#include "pf/formats/mapc/occ.hpp"
#include "pf/formats/mapc/octm.hpp"
#include "pf/formats/mapc/parm.hpp"
#include "pf/formats/mapc/phys.hpp"
#include "pf/formats/mapc/pnvm.hpp"
#include "pf/formats/mapc/prp2.hpp"
#include "pf/formats/mapc/reso.hpp"
#include "pf/formats/mapc/rive.hpp"
#include "pf/formats/mapc/shad.hpp"
#include "pf/formats/mapc/shex.hpp"
#include "pf/formats/mapc/shor.hpp"
#include "pf/formats/mapc/snd.hpp"
#include "pf/formats/mapc/surf.hpp"
#include "pf/formats/mapc/tlfs.hpp"
#include "pf/formats/mapc/trn.hpp"
#include "pf/formats/mapc/trni.hpp"
#include "pf/formats/mapc/watr.hpp"
#include "pf/formats/mapc/zon2.hpp"
#include "pf/reader.hpp"

namespace pf {

template <typename Config>
using MapReaderWithConfig = Reader<FourCC::mapc, Config>;

using MapReader = Reader<FourCC::mapc>;

}  // namespace pf

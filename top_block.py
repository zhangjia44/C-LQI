#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Top Block
# Generated: Fri Aug 10 08:11:40 2018
##################################################

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from PyQt4 import Qt
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import fft
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.fft import window
from gnuradio.filter import firdes
from optparse import OptionParser
import bitTobyte
import byteTo6bit
import carrier48
import carrier_corresponding
import deconvolution
import decycleprefix
import deinterleaver
import demapping
import descramble
import sys


class top_block(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Top Block")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Top Block")
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
            pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "top_block")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################
        self.fft_vxx_0_1 = fft.fft_vcc(64, True, (window.rectangular(64)), True, 1)
        self.descramble_descramble_0 = descramble.descramble(9)
        self.demapping_my_demapping_64_0 = demapping.my_demapping_64(64)
        self.deinterleaver_deinterleaver_0 = deinterleaver.deinterleaver()
        self.decycleprefix_decycleprefix_0 = decycleprefix.decycleprefix()
        self.deconvolution_deconvolution_0 = deconvolution.deconvolution()
        self.carrier_corresponding_carrier_correponding_0 = carrier_corresponding.carrier_correponding()
        self.carrier48_carrier48_0 = carrier48.carrier48()
        self.byteTo6bit_byteTo6bit_0 = byteTo6bit.byteTo6bit()
        self.blocks_stream_to_vector_0 = blocks.stream_to_vector(gr.sizeof_gr_complex*1, 80)
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_gr_complex*1, "/home/zj/学姐实验/8.10/zigbee9_double", False)
        self.blocks_file_sink_0_0_0_1_0_0 = blocks.file_sink(gr.sizeof_char*27, "/home/zj/学姐实验/8.10/zigbee9_webee", False)
        self.blocks_file_sink_0_0_0_1_0_0.set_unbuffered(False)
        self.bitTobyte_bitTobyte_1 = bitTobyte.bitTobyte()

        ##################################################
        # Connections
        ##################################################
        self.connect((self.bitTobyte_bitTobyte_1, 0), (self.blocks_file_sink_0_0_0_1_0_0, 0))    
        self.connect((self.blocks_file_source_0, 0), (self.blocks_stream_to_vector_0, 0))    
        self.connect((self.blocks_stream_to_vector_0, 0), (self.decycleprefix_decycleprefix_0, 0))    
        self.connect((self.byteTo6bit_byteTo6bit_0, 0), (self.deinterleaver_deinterleaver_0, 0))    
        self.connect((self.carrier48_carrier48_0, 0), (self.byteTo6bit_byteTo6bit_0, 0))    
        self.connect((self.carrier_corresponding_carrier_correponding_0, 0), (self.carrier48_carrier48_0, 0))    
        self.connect((self.deconvolution_deconvolution_0, 0), (self.descramble_descramble_0, 0))    
        self.connect((self.decycleprefix_decycleprefix_0, 0), (self.fft_vxx_0_1, 0))    
        self.connect((self.deinterleaver_deinterleaver_0, 0), (self.deconvolution_deconvolution_0, 0))    
        self.connect((self.demapping_my_demapping_64_0, 0), (self.carrier_corresponding_carrier_correponding_0, 0))    
        self.connect((self.descramble_descramble_0, 0), (self.bitTobyte_bitTobyte_1, 0))    
        self.connect((self.fft_vxx_0_1, 0), (self.demapping_my_demapping_64_0, 0))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "top_block")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate


def main(top_block_cls=top_block, options=None):

    from distutils.version import StrictVersion
    if StrictVersion(Qt.qVersion()) >= StrictVersion("4.5.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def quitting():
        tb.stop()
        tb.wait()
    qapp.connect(qapp, Qt.SIGNAL("aboutToQuit()"), quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()

// ==UserScript==
// @name         Fuck ACMP
// @namespace    http://tampermonkey.net/
// @version      2025-06-18
// @description  try to take over the world!
// @author       You
// @match        https://acmp.ru/*
// @icon         https://www.google.com/s2/favicons?sz=64&domain=acmp.ru
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    function VPIZDY() {
        const bg = document.querySelectorAll('[background]');
        bg.forEach(element => {
            element.removeAttribute('background');
        });

        const bgcol = document.querySelectorAll('[bgcolor]');
        bgcol.forEach(element => {
            element.removeAttribute('bgcolor');
        });
    }

    function removeTitleImage() {
        const titleImage = document.querySelector('img[src="/images/title.png"]');
        if (titleImage) {
            titleImage.remove();
        }
    }

    VPIZDY();
    removeTitleImage();

    const observer = new MutationObserver(mutations => {
        mutations.forEach(mutation => {
            mutation.addedNodes.forEach(node => {
                if (node.nodeType === Node.ELEMENT_NODE) {
                    if (node.hasAttribute('background') || node.hasAttribute('bgcolor')) {
                        node.removeAttribute('background');
                        node.removeAttribute('bgcolor');
                    }
                    const elementsToClean = node.querySelectorAll('[background], [bgcolor]');
                    elementsToClean.forEach(el => {
                        el.removeAttribute('background');
                        el.removeAttribute('bgcolor');
                    });
                    
                    // Check if the added node is the title image or contains it
                    if (node.tagName === 'IMG' && node.src && node.src.includes('/images/title.png')) {
                        node.remove();
                    }
                    const titleImageInNode = node.querySelector('img[src="/images/title.png"]');
                    if (titleImageInNode) {
                        titleImageInNode.remove();
                    }
                }
            });
        });
    });
    observer.observe(document.body, {
        childList: true,
        subtree: true,
        attributes: true,
        attributeFilter: ['background', 'bgcolor']
    });
})(); 